//!@file
//!@brief Driver to run the Character Observer.
//!@author Brandon Amyot - 26990940

#include "Character.h"
#include "CharacterObserver.h"
#include <iostream>
using namespace std;

int main(void) {
	Character *peter = new Character(1,10,10,12,8,14,10);

	CharacterObserver *observer = new CharacterObserver(peter);

	cout << "Original character data." << endl << endl;
	peter->getScores();
	cout << "\nSetting strength to new value." << endl << endl;
	peter->setStrength(12);
	cout << "\nTaking 5 damage." << endl << endl;
	peter->getHit(5);
}