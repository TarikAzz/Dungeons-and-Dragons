
//! @file 
//! @brief Implementation file for the Map class
//!
#include "Map.h"
using namespace std;

IMPLEMENT_SERIAL(Map, CObject, 1)

Map::Map() 
{
	
}
//! Non-default constructor bulding a blank map with specified dimenions and START/END coordinates
Map::Map(int row, int col, int startX, int startY, int endX, int endY, CString name) 
{
	this->row = row;
	this->column = col;
	this->startX = startX;
	this->startY = startY;
	this->endX = endX;
	this->endY = endY;
	this->mapName = name;
	this->grid = new CString*[this->row];

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
	this->grid[this->startX][this->startY] = 'S';
	this->grid[this->endX][this->endY] = 'E';
}

Map::~Map()
{
}

int Map::getRow()
{
	return Map::row; 
}

CString** Map::getGrid()
{
	
	return grid;
}

int Map::getStartX()
{
	return Map::startX;
}

int Map::getStartY()
{
	return Map::startY;
}

int Map::getEndX()
{
	return Map::endX;
}

int Map::getEndY()
{
	return Map::endY;
}

int Map::getCol()
{ 
	return column; 
}

void Map::fillCell(int x, int y, string obj) 
{


	while (true) 
	{
		/*if (x == startX || y == startY || x == endX || y == endY)
		{
			cout<<"Cannot change START and END coordinates"
		}*/

		
		if (obj == "W" || obj == "P" || obj == "M" || obj == "C")
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

}

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

bool Map::validatePath(int x, int y)
{
	// If x, y is outside maze, return false.
	if (x < 0 || x > row-1 || y < 0 || y > column-1)
		return false;

	// If x,y is the goal, return true.
	if (grid[x][y] == 'E') {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (grid[i][j] == '+')
					grid[i][j] = '_';
			}
		}
		grid[startX][startY] = 'S';
		return true;
	}

	// If x,y is occupied or has been visited
	if (grid[x][y] == 'W' || grid[x][y] == '+')
		return false;

	// Mark where the algorithm has gone
	grid[x][y] = '+';

	// If right of x,y is open, go right.
	if (validatePath(x, y+1) == true) {
		return true;
	}
	// If up of x,y is open, go straight.
	else if (validatePath(x-1, y) == true) {
		return true;
	}
	// If left of x,y is open, go left.
	else if (validatePath(x, y-1) == true) {
		return true;
	}
	// If down north of x,y is open, go down.
	else if (validatePath(x+1, y) == true) {
		return true;
	}
	else {
		grid[x][y] = '_';
		return false;
	}
}

void Map::printMap()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			CString cs = grid[i][j];
			CT2CA pszConvertedAnsiString(cs);
			std::string strStd(pszConvertedAnsiString);
			
			cout << strStd << " ";
		}
		cout << endl;
	}
}
//! Commenting out all methods pertaining to TEXT FILE for testing



void Map::save()
{
	
	CFile theFile;

	theFile.Open(mapName, CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);
	this->Serialize(archive);
	archive.Close();
	theFile.Close();
}

void Map::load(string name)
{

	CFile theOtherFile;
	//open a file in input mode
	theOtherFile.Open(CString(name.c_str()), CFile::modeRead);
	//Create a CArchive and connect it to the file
	CArchive otherArchive(&theOtherFile, CArchive::load);
	this->Serialize(otherArchive);
	otherArchive.Close();
	theOtherFile.Close();

}

void Map::createMap()
{
	string ans;
	cout << "\nPlease enter a file name: ";
	string fileName;
	cin >> fileName;

	do
	{
		cout << "Map Creation:" << endl;

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

		Map* map1 = new Map(row, col, startX, startY, endX, endY, CString(fileName.c_str()));
		string obj;
		int x = 0;
		int y = 0;
		do
		{
			cout << "\n-----Displaying Current map-------" << endl;
			map1->printMap();
			cout << "\nEnter the cell coordinate you would like to change (x followed by y) or Enter a negative numbers to stop: ";
			cin >> row;
			cin >> col;
			if (row < 0 || col < 0)
				break;
			cout << "\nEnter game object to add, [W: Wall, C: Chest, M: Monster]: ";
			cin >> obj;
			map1->fillCell(row, col, obj);
		} while (true);

		if (map1->validatePath(startX, startY))
		{
			cout << "success!" << endl;
//		cout << "\n\nMap has not been validated! restarting\n\n new map:\n" << endl;
		}

		map1->printMap();

		cout << "Do you want to create another level in this campaign (y/n)?: ";
		cin >> ans;
		if (ans == "y")
		{
			cout << "\nPlease enter a file name: ";
			cin >> fileName;
			map1->nextName = CString(fileName.c_str());
		}
		map1->save();

	} while (ans == "y");
	cout << "\nCampaign finished!" << endl;
}

void Map::editMap(string name)
{	
	cout << "Editing " << name << " map" << endl;;
	
	Map* m= new Map();
	m->load(name);
	int i = 0;
	int j = 0;
	string obj;
	do
	{
		cout << "\n-----Displaying Current map-------" << endl;
		m->printMap();
		cout << "\nEnter the cell coordinate you would like to change (x followed by y) or Enter a negative numbers to stop: ";
		cin >> i;
		cin >> j;
		if (i < 0 || j < 0)
			break;
		cout << "\nEnter game object to add, [W: Wall, C: Chest, M: Monster]: ";
		cin >> obj;
		m->fillCell(i, j, obj);
	} while (true);
	m->save();
	cout << "Changes have been saved!" << endl;
}


void Map::Serialize(CArchive & archive)
{
	CObject::Serialize(archive);

	if (archive.IsStoring())
	{
		 archive << row << column <<startX << startY << endX << endY << mapName << nextName;
		 for (int i = 0; i < row ; i++)
		 {
			 for (int j = 0; j < column ; j++)
			 {
				 archive << grid[i][j];
			 }
		 }
	}
		

	else
	{
		
		//int row, column;
		archive >> row;
		archive >> column;

		archive >> startX >> startY >> endX >> endY >> mapName >> nextName;
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


/*

this->grid = new CString*[this->row];

for (int i = 0; i < this->row; i++)
{
this->grid[i] = new CString[this->column];
}

int row;
int column;
char** grid;
int startX;
int startY;
int endX;
int endY;
string mapName;
string nextName;
*/
