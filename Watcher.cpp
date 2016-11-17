//! @file 
//! @author Vance De Waele - 25149436
//! Concrete implementation  of the Observer class. Allows the Character class
//! to be observed in the main method at the end of this file.
//! Included Character.h, Watcher.h, iostream and string. Character.h was
//! necessary to have the class be observed. Watcher.h was included for obvious
//! reasons. String and iostream were included to allow certain functionalities
//! in the main method and the member methods.


#include "Watcher.h"
#include "Character.h"
#include "gfx.h"
#include "dice.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//! Default constructor. Does not need definition as it is never used.
Watcher::Watcher() {};

//! Constructor that takes a pointer to a Character(subject) and attaches
//! it to this Watcher class (obeserver).
Watcher::Watcher(Character* hero) {
	_subject = hero;
	_subject->Attach(this);
}

//! Destructor that detaches this Watcher (observer) from its subject.
Watcher::~Watcher() {
	_subject->Detach(this);
}

//! Method that updates observers of the subject. It calls for the
//! update to use the display function to verify the update.
void Watcher::Update() {
	Display();
}

//! Method that displays the attributes of a subject. In this case,
//! it calls on the getScores method of the Character class to show
//! the values stored by the object.
void Watcher::Display() {
	_subject->getScores();
}
//! Method that allows an observer to find out the level of a Character.
//! It uses the attached subject and checks the level it has and returns
//! its value as an integer.
int Watcher::findOutLevel() {
	return _subject->getLevel();
}
//! Method that allows an observer to find out if a Character is still alive.
//! It verifies if the Character object's hit points are above 0 and displays
//! a message in the console to declare if a Character is alive or dead. Though
//! it returns an integer for numercial comparison in tests, it can be refactored
//! in the future to return a boolean or simply nothing.
int Watcher::characterIsDead() {
	if (_subject->getHitPoints() > 0) {
		cout << "Still alive!";
		return 1;
	}
	else
		cout << "They are no longer part of this world.";
	return 0;
}

//! Method for creating a Character object using user input.
Character* Watcher:: createHero() {
	cout << "*********************************************************************************" << endl;
	cout << "        --------------- Character Creator/Selector --------------" << endl;
	cout << "*********************************************************************************" << endl;
	cout << "\nLet's start our journey by selecting our hero! " << endl;
	cout << "Do you want to create or load a character?" << endl;
	//perfect user input: create or load
	string choice;
	cin >> choice;
	if (choice == "create") {
		cout << "\n***CREATE YOUR HERO***" << endl;
		cout << "First, enter a name for your hero: " << endl;
		string givenName;
		cin >> givenName;

		cout << "Welcome " << givenName << " to the world of Dungeon and Dragons!" << endl;
		cout << "What level are you going to start at? : " << endl;
		int level;
		cin >> level;

		//! I know the rule is to roll 6 times then pick top three...will refactor this in later versions.
		cout << "Let's roll our die and figure out your stats!" << endl;
		Dice* creatorDice = new Dice();
		int scores[6];
		int s, d, c, i, w, h;
		int index = 0;

		for (int i = 1; i < 7; i++) {
			cout << "Roll " << i << ":" << endl;
			scores[i - 1] = creatorDice->Roll("3d6"); creatorDice->Reset();
		}
		delete creatorDice;
		cout << "Here are your rolls: \n" << endl;
		for (int i = 1; i < 7; i++) {
			cout << "Roll " << i << ":" << scores[i - 1] << "\t\tIndex: " << i - 1 << endl;
		}
		cout << "Which value do you want for Strength? Enter corresponding index: " << endl;
		cin >> index;
		s = scores[index];

		cout << "Which value do you want for Dexterity? Enter corresponding index: " << endl;
		cin >> index;
		d = scores[index];

		cout << "Which value do you want for Constitution? Enter corresponding index: " << endl;
		cin >> index;
		c = scores[index];

		cout << "Which value do you want for Intelligence? Enter corresponding index: " << endl;
		cin >> index;
		i = scores[index];

		cout << "Which value do you want for Wisdom? Enter corresponding index: " << endl;
		cin >> index;
		w = scores[index];

		cout << "Which value do you want for Charisma? Enter corresponding index: " << endl;
		cin >> index;
		h = scores[index];

		Character* player = new Character(givenName, level, s, d, c, i, w, h);
		player->isValidCharacter();
		player->getScores();
		system("PAUSE");

		player->displayWornItems();
		system("PAUSE");
		player->displayInventory();
		system("PAUSE");
		Item* testItem = new Item("Helm of Confusion", 5, 5, 0, 0, 0, 0, 0, 0);
		player->equipItem(testItem);
		player->displayWornItems();
		player->getScores();

		cout << "Here is your hero: \n" << endl;
		player->getScores();
		cout << "Saving hero to file..." << endl;
		system("PAUSE");

		CFile characterSave;
		characterSave.Open((CString(player->getName().c_str())), CFile::modeCreate | CFile::modeWrite);
		CArchive archive(&characterSave, CArchive::store);
		player->Serialize(archive);

		ofstream outputfilestream;

		outputfilestream.open("Characters.txt", std::ios_base::app);//Switch to make work please
		outputfilestream << player->getName() << " " << endl;
		outputfilestream.close();

		archive.Close(); characterSave.Close();
		return player;
	}
	//! Assuming that the player has perfect user input and knows what name to load.
	if (choice == "load") {

		string names;
		ifstream inputfilestream;
		inputfilestream.open("Characters.txt");
		while (inputfilestream >> names) {
			cout << names << endl;
		}

		cout << "Please type in the name of the character you wish to load: " << endl;
		string enterFile;
		cin >> enterFile;
		CString loadThis = (CString(enterFile.c_str()));
		CFile loadFile;
		loadFile.Open((loadThis), CFile::modeRead);
		CArchive otherArchive(&loadFile, CArchive::load);

		Character* player = new Character();
		player->Serialize(otherArchive);
		otherArchive.Close(); loadFile.Close();
		return player;
	}
}
