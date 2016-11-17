
//! @file
//! @author Tarik Azzouni - 27013701
//! @brief Implementation file for the Map class
//!
#include "Map.h"
using namespace std;

IMPLEMENT_SERIAL(Map, CObject, 1)
//! Default constructor, defined empty in order for the MFC serialization to work properly
Map::Map() 
{
	
}
//! Non-default constructor bulding a blank map with specified dimenions and START/END coordinates
Map::Map(int row, int col, int startX, int startY, int endX, int endY, CString name, Character* play) 
{
	this->row = row;
	this->column = col;
	this->startX = startX;
	this->startY = startY;
	this->endX = endX;
	this->endY = endY;
	this->mapName = name;
	this->grid = new CString*[this->row];
	this->player = play;

	for (int i = 0; i < this->row; i++)
	{
		this->grid[i] = new CString[this->column];
	}
	//! Assigning the values of each cell to empty/walkable
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			this->grid[i][j] = '_';
		}
	}
	//Sets the start and end coordinates
	this->grid[this->startX][this->startY] = 'S';
	this->grid[this->endX][this->endY] = 'E';
}
//! Destructor
Map::~Map()
{
	delete player;
	player = NULL;
}

//! Returns the row size
int Map::getRow()
{
	return Map::row; 
}
//! Returns the column size
int Map::getCol()
{
	return Map::column;
}
//! Returns the grid
CString** Map::getGrid()
{
	
	return grid;
}
//! Returns the Start x coordinate
int Map::getStartX()
{
	return Map::startX;
}
//! Returns the Start x coordinate
int Map::getStartY()
{
	return Map::startY;
}
//! Returns the End x index
int Map::getEndX()
{
	return Map::endX;
}
//! Returns the end Y index
int Map::getEndY()
{
	return Map::endY;
}
//! Fills a cell based on 
void Map::fillCell(int x, int y, string obj) 
{
	while (true) 
	{
		/*if (x == startX || y == startY || x == endX || y == endY)
		{
			cout << "Cannot change START and END coordinates" << endl;
		}
*/
		if (obj == "W" || obj == "O" || obj == "L" || obj == "C" || obj == "G")
		{
			cout << "Valid!" << endl;
			char c = obj[0];
			cout << "THIS IS THE CHAR: " << c << endl;
			this->grid[x][y] = c;
			break;
		}

		else
		{
			cout << "Not valid, enter new input: " << endl;
			cin >> obj;
		}
	}
	//! Gets called for use in the Observer pattern
	Notify();
	return;
}

//! Checks if a cell is filled with any other other than an empty space
bool Map::isOccupied(int x, int y)
{
	if (this->grid[x][y] != '_')
	{
		
		return false;
	}
	else
	{
		return true;
	}
	
}
//! Prints the Map grid
void Map::printMap()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			//! Since each cell is composed of CStrings, I converted the CString to a 
			//! string with this small code
			CString cs = grid[i][j];
			CT2CA pszConvertedAnsiString(cs);
			string strStd(pszConvertedAnsiString);
			cout << strStd << " ";
		}
		cout << endl;
	}
}

//! Verifies that there is a winning path form the start to end
bool Map::validatePath(int x, int y)
{
	printMap();
	// If x, y is outside maze, return false.
	if (x < 0 || x > row - 1 || y < 0 || y > column - 1)
		return false;

	// If x,y is the goal, return true.
	if (grid[x][y] == 'E') {
		// restore the map
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (grid[i][j] == '+')
					grid[i][j] = '_';
			}
		}
		grid[startX][startY] = 'S';
		grid[endX][endY] = 'E';
		return true;
	}

	// If x,y is occupied or has been visited
	if (grid[x][y] == 'W' || grid[x][y] == '+')
		return false;

	// Mark where the algorithm has gone; ignore Monsters and Chests
	if (grid[x][y] == 'M') {
		grid[x][y] = 'M';
	}
	else if (grid[x][y] == 'C')
		grid[x][y] = 'C';
	else
		grid[x][y] = '+';

	// If right of x,y is open, go right.
	if (validatePath(x, y + 1) == true) {
		return true;
	}
	// If down north of x,y is open, go down.
	else if (validatePath(x + 1, y) == true) {
		return true;
	}
	// If up of x,y is open, go straight.
	else if (validatePath(x - 1, y) == true) {
		return true;
	}
	// If left of x,y is open, go left.
	else if (validatePath(x, y - 1) == true) {
		return true;
	}
	else {
		if (grid[x][y] == '+')
			grid[x][y] = '_';
		return false;
	}
}
//! Serialized and saves the Map Object to a text file
void Map::save()
{
	//! Makes a new CFile
	CFile theFile;
	//! Opens thein outputmode
	theFile.Open(mapName, CFile::modeCreate | CFile::modeWrite);
	//! Creates a CArchive output 
	CArchive archive(&theFile, CArchive::store);
	//! Serializes this instance of the Map to the archive
	this->Serialize(archive);
	archive.Close();
	theFile.Close();
}
//! Deserailizes and loads a Map object
Map* Map::load(string name)
{
	
	CFile theOtherFile;
	//! Opens a specified file in input mode
	theOtherFile.Open(CString(name.c_str()), CFile::modeRead);
	//! Creates a CArchive and connect it to the file
	CArchive otherArchive(&theOtherFile, CArchive::load);
	//! Serializes this instance of the Map to the archive
	this->Serialize(otherArchive);
	otherArchive.Close();
	theOtherFile.Close();
	return this;

}

//! Creates a map based on user input, which includes text prompts
Map* Map::createMap(Character* player)
{
	cout << "*********************************************************************************" << endl;
	cout << "        --------------- Create your Dungeon --------------" << endl;
	cout << "*********************************************************************************" << endl;
	ofstream outStream;
	string ans;
	cout << "Enter a file name: ";
	string fileName;
	cin >> fileName;
	Map* map1;
	Map* map2;
	do
	{
		//Assuming perfect user input
		cout << "\nMap Creation:" << endl;

		cout << "\nEnter width of map: ";
		int row;
		cin >> row;
		cout << "\nEnter length of map: ";
		int col;
		cin >> col;
		cout << "\nEnter Start coordinates (x followed by y): ";
		int startX, startY;
		cin >> startX;
		cin >> startY;
		cout << "\nEnter End coordinates (x followed by y): ";
		int endX, endY;
		cin >> endX;
		cin >> endY;

		map1 = new Map(row, col, startX, startY, endX, endY, CString(fileName.c_str()), player);
		string obj;
		int x = 0;
		int y = 0;
		do
		{
			cout << "\n-----Displaying Current map-------" << endl;
			map1->printMap();
			cout << "\nEnter the cell coordinate you would like to change (x followed by y) or Enter a negative numbers to stop: ";
			cin >> x;
			cin >> y;

			if (x < 0 || y < 0)
			{
				 
				if (map1->validatePath(startX, startY))
				{
					break;
				}
				else
				{
					cout << "There is no clear winning path!" << endl;
					cout << "\nEnter the cell coordinate you would like to change (x followed by y): ";
					cin >> x;
					cin >> y;
				}
				break;
			
			}
			cout << "\nEnter game object to add, [W: Wall, C: Chest, G: Goblin, L: Gnoll, O: Ogre]: ";
			cin >> obj;
			map1->fillCell(x, y, obj);
		
		} while (true);
			
		map1->printMap();

		cout << "Do you want to create another level in this campaign (y/n)?: ";
		cin >> ans;
		if (ans == "y")
		{
			cout << "\nPlease enter a file name: ";
			cin >> fileName;
			map1->nextName = CString(fileName.c_str());
		}
		outStream.open("Maps.txt", std::ios_base::app);
		outStream << fileName << endl;
		outStream.close();
		map1->save();

	} while (ans == "y");
	cout << "\nCampaign finished!"<<endl;
	return map1;
}

//! Edits an existing Map, based on user input
Map* Map::editMap(Map* map)
{	
	CString cs = map->getMapName();
	CT2CA pszConvertedAnsiString(cs);
	string strStd(pszConvertedAnsiString);
	cout << "\nEditing " << strStd<< " map" << endl;;
	int i = 0;
	int j = 0;
	string obj;
	do
	{
		cout << "\n-----Displaying Current map-------" << endl;
		map->printMap();
		cout << "\nEnter the cell coordinate you would like to change (x followed by y) or Enter a negative numbers to stop: ";
		cin >> i;
		cin >> j;
		if (i < 0 || j < 0)
			break;
		cout << "\nEnter game object to add, [W: Wall, C: Chest, G: Goblin, L: Gnoll, O: Ogre]: ";
		cin >> obj;
		map->fillCell(i, j, obj);
	} while (true);
	map->save();
	cout << "Changes have been saved!" << endl;
	return map;
}  

//! Serializes and deserializes a Map object to a Text file
void Map::Serialize(CArchive & archive)
{
	CObject::Serialize(archive);

	//!Serializes
	if (archive.IsStoring())
	{
		archive << row << column << startX << startY << endX << endY << mapName << nextName;//<< player;
		 for (int i = 0; i < row ; i++)
		 {
			 for (int j = 0; j < column ; j++)
			 {
				 archive << grid[i][j];
			 }
		 }
	}
	//! Deseriliazes
	else
	{
		archive >> row;
		archive >> column;

		archive >> startX >> startY >> endX >> endY >> mapName >> nextName;//>>player;
		grid = new CString*[row];
		for (int i = 0; i < row; i++)
		{
			grid[i] = new CString[column];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				
				archive >> grid[i][j];
			}
		}
	}	
}
//! Moves the player P to a desried location
void Map::move()
{
	cout << "*********************************************************************************" << endl;
	cout << "        --------------- Get ready to play! --------------" << endl;
	cout << "*********************************************************************************" << endl;
	cout << "CONTROLS: Press W to move UP, Press S to move DOWN, Press A to move LEFT, Press D to move RIGHT\n Pess I to access the player's scores and Inventory" << endl;
	system("PAUSE");
	string input;
	int playerX = startX;
	int playerY = startY;
	CString temp = grid[playerX][playerY];
	while(true)
	{
		if(grid[playerX][playerY])

		//! Comment this out for the Observable
		printMap();
		
			cin >> input;
			//! Checks if you can go Up
			if (input == "W")
			{
				if (playerX - 1 < 0 || grid[playerX-1][playerY]=='W')
				{
					cout << "Invalid move, try again!\n";
				}
				else if (grid[playerX - 1][playerY] == 'O')
				{
					Ogre o(player->getLevel());
					grid[playerX][playerY] = temp;
					playerX -= 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints()+o.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << o.giveHeroExp() << endl;
				}
				else if (grid[playerX - 1][playerY] == 'G')
				{
					Goblin g(player->getLevel());
					grid[playerX][playerY] = temp;
					playerX -= 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints() + g.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << g.giveHeroExp() << endl;
				}
				else if (grid[playerX - 1][playerY] == 'L')
				{
					Gnoll l(player->getLevel());
					grid[playerX][playerY] = temp;
					playerX -= 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints() + l.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << l.giveHeroExp() << endl;

				}
				else if (grid[playerX - 1][playerY] == 'E')
				{
					
					grid[playerX][playerY] = temp;
					playerX -= 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					cout << "-------You have cleared the dungeon!-------" << endl;
					cout << "------You leveled up!-------" << endl;
					system("PAUSE");
					player->setLevel(player->getLevel() + 1);
					player->getScores();
					break;
				}
				else if (grid[playerX - 1][playerY] == 'C')
				{
					Gnoll l(player->getLevel());
					grid[playerX][playerY] = temp;
					playerX -= 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					Treasure* t = new Treasure;
					t->setTreasureContents();
					player->equipItem(t->getItemFromTreasure());
					cout << "You picked up: ";
					t->display();
					cout << endl;

				}
				else
				{
					grid[playerX][playerY] = temp;
					playerX -= 1;
					temp = grid[playerX][playerY];
					grid[playerX][playerY] = 'P';
				}
				
			}
			//! Checks if you can go down
			if (input == "S")
			{
				

				if (playerX+1 > row-1 || grid[playerX+1][playerY] == 'W')
				{
					cout << "Invalid move, try again!\n";
				}
				else if (grid[playerX + 1][playerY] == 'O')
				{
					Ogre o(player->getLevel());
					grid[playerX][playerY] = temp;
					playerX += 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints() + o.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << o.giveHeroExp() << endl;
				}
				
				else if (grid[playerX + 1][playerY] == 'G')
				{
					Goblin g(player->getLevel());
					grid[playerX][playerY] = temp;
					playerX += 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints() + g.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << g.giveHeroExp() << endl;
				}
				else if (grid[playerX + 1][playerY] == 'L')
				{
					Gnoll l(player->getLevel());
					grid[playerX][playerY] = temp;
					playerX += 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints() + l.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << l.giveHeroExp() << endl;
				}
				else if (grid[playerX + 1][playerY] == 'E')
				{

					grid[playerX][playerY] = temp;
					playerX += 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					cout << "-------You have cleared the dungeon!-------" << endl;
					cout << "------You leveled up!-------" << endl;
					system("PAUSE");
					player->setLevel(player->getLevel() + 1);
					player->getScores();
					break;
					
				}
				else if (grid[playerX + 1][playerY] == 'C')
				{
					Goblin g(player->getLevel());
					grid[playerX][playerY] = temp;
					playerX += 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					Treasure* t = new Treasure;
					t->setTreasureContents();
					player->equipItem(t->getItemFromTreasure());
					cout << "You picked up: ";
					t->display();
					cout << endl;
					
				}
				else 
				{
					grid[playerX][playerY] = temp;
					playerX += 1;
					temp = grid[playerX][playerY];
					grid[playerX][playerY] = 'P';
				}
				

			}
			//! Checks if you can go right
			if (input == "D")
			{
				

				if ( playerY+1> column-1 || grid[playerX][playerY+1]=='W')
				{
					cout << "Invalid move, try again!\n";
				}
				else if (grid[playerX][playerY+1] == 'O')
				{
					Ogre o(player->getLevel());
					grid[playerX][playerY] = temp;
					playerY += 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints() + o.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << o.giveHeroExp() << endl;
				}
				else if (grid[playerX][playerY+1] == 'G')
				{
					Goblin g(player->getLevel());
					grid[playerX][playerY] = temp;
					playerY += 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints() + g.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << g.giveHeroExp() << endl;
				}
				else if (grid[playerX][playerY+1] == 'L')
				{
					Gnoll l(player->getLevel());
					grid[playerX][playerY] = temp;
					playerY += 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints() + l.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << l.giveHeroExp() << endl;

				}
				else if (grid[playerX][playerY+1] == 'E')
				{

					grid[playerX][playerY] = temp;
					playerY += 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					cout << "-------You have cleared the dungeon!-------" << endl;
					cout << "------You leveled up!-------" << endl;
					system("PAUSE");
					player->setLevel(player->getLevel() + 1);
					player->getScores();
					break;

				}
				else if (grid[playerX][playerY+1] == 'C')
				{
					Goblin g(player->getLevel());
					grid[playerX][playerY] = temp;
					playerY += 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					Treasure* t = new Treasure;
					t->setTreasureContents();
					player->equipItem(t->getItemFromTreasure());
					cout << "You picked up: ";
					t->display();
					cout << endl;

				}
				else
				{
					grid[playerX][playerY] = temp;
					playerY += 1;
					temp = grid[playerX][playerY];
					grid[playerX][playerY] = 'P';
				}

			}
			if (input == "I")
			{
				player->getScores();
				player->displayWornItems();
			}

			//! Checks if you can go left
			if (input == "A")
			{

				if ( playerY-1 < 0 || grid[playerX][playerY-1]=='W')
				{
					cout << "Invalid move, try again!\n";
				}

				else if (grid[playerX][playerY-1] == 'O')
				{
					Ogre o(player->getLevel());
					grid[playerX][playerY] = temp;
					playerY -= 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints() + o.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << o.giveHeroExp() << endl;
				}
				else if (grid[playerX][playerY - 1] == 'G')
				{
					Goblin g(player->getLevel());
					grid[playerX][playerY] = temp;
					playerY -= 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints() + g.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << g.giveHeroExp() << endl;
				}
				else if (grid[playerX][playerY - 1] == 'L')
				{
					Gnoll l(player->getLevel());
					grid[playerX][playerY] = temp;
					playerY -= 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					player->setSpecificExp(player->getExpPoints() + l.giveHeroExp());
					cout << "You defeated an enemy! You have gained: " << l.giveHeroExp() << endl;
				}
				else if (grid[playerX][playerY - 1] == 'E')
				{

					grid[playerX][playerY] = temp;
					playerY -= 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					cout << "-------You have cleared the dungeon!-------" << endl;
					cout << "------You leveled up!-------" << endl;
					system("PAUSE");
					player->setLevel(player->getLevel() + 1);
					player->getScores();
					break;
				}
				else if (grid[playerX][playerY - 1] == 'C')
				{
					Goblin g(player->getLevel());
					grid[playerX][playerY] = temp;
					playerY -= 1;
					temp = '_';
					grid[playerX][playerY] = 'P';
					Treasure* t = new Treasure;
					t->setTreasureContents();
					player->equipItem(t->getItemFromTreasure());
					cout << "You picked up: " ;
					t->display();
					cout << endl;

				}
				else
				{
					grid[playerX][playerY] = temp;
					playerY -= 1;
					temp = grid[playerX][playerY];
					grid[playerX][playerY] = 'P';
				}
			}
			Notify();
		}
}


