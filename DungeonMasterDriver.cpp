#include "Map.h"
#include "Watcher.h"
#include "gfx.h"

int main()
{
	cout << "*********************************************************************************" << endl;
	cout << "        --------------- Welcome to DUNGEONS & DRAGONS --------------" << endl;
	cout << "*********************************************************************************" << endl<<endl;
	Map* mapMain = new Map();
	Watcher* test = new Watcher();
	mapMain->setPlayer(test->createHero());
	//cout << "\n\nDISPLAYY\n\n" << endl;
	cout << "LVL is: " << mapMain->getPlayer()->getLevel() << endl;
	cout << "Do you want to create or load map?" << endl;
	string ans;
	cin >> ans;

	if (ans == "create")
	{
		//Map* mapMain = new Map();
		mapMain =Map::createMap(mapMain->getPlayer());
		mapMain->printMap();
		mapMain->getPlayer()->getScores();
		mapMain->move();
	}
	else if (ans == "load")
	{
		ifstream inStream;
		string list;
		cout << "List of saved maps: " << endl;
		inStream.open("Maps.txt");
		while (inStream >> list) {
			cout << list << endl;
		}
		inStream.close();
		cout << "Enter the Map name you would like to load" << endl;
		string input;
		cin >> input;
		cout << "**********LOADING*************" << endl;
		Map* mapMain2 = new Map();
		mapMain2->load(input);
		mapMain2->printMap();
		mapMain2->getPlayer()->getScores();
		cout << "\nDo you want to use the character you just created?: ";
		cin >> input;
		if (input == "y")
		{
			mapMain2->setPlayer(mapMain->getPlayer());
		}
		mapMain2->getPlayer()->getScores();
		cout << "Do you want to edit this map/save this character to this map? (y/n)" << endl;
		cin >> input;
		if (input == "y")
		{
			mapMain2 = Map::editMap(mapMain2);
			mapMain2->printMap();
			mapMain2->getPlayer()->getScores();
			mapMain2->move();
			delete mapMain2;
			mapMain2 = NULL;

		}
		else
		{
			mapMain2->move();
			delete mapMain2;
			mapMain2 = NULL;
		}

	}
		

//	}
	/*Character* c= new Character();
	Map* mapMain = new Map(5, 5, 1, 1, 4, 4,"name", c);
	mapMain->fillCell(3, 3, "O");
	mapMain->fillCell(3, 4, "L");
	mapMain->fillCell(2, 3, "G");
	cout << "This is the lvl: "<<mapMain->getPlayer()->getLevel() << endl;
	mapMain->move(5);*/
	delete mapMain;
	mapMain = NULL;

	return 0;
}