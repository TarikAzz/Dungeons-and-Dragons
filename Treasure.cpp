//! Treasure Implementation File

#include "Treasure.h"
#include <afx.h>



//! Defualt Constructor
Treasure::Treasure()
{
}

// Destructor
Treasure::~Treasure()
{
}

// A method to get items from Chest
Item* Treasure::getItemFromTreasure() {
	std::string answer;
	display();

	cout << "WOULD YOU LIKE TO LOOT THIS ITEM? (Y/N)" << endl;

	cin >> answer;

	if (answer == "Y" || answer == "y") {

		return treasureItems[0];

	}
	loot = NULL;
	delete loot;
	
	return NULL;

}

//! Method to determin random item;
void Treasure::setTreasureContents() {

	srand(time(NULL));
	int random = (rand() % 8 + 1);
	switch (random) {
	case 1:
	{loot = new Armor("Light Armor", 5); break; }
	case 2:
	{loot = new Belt("Medium Belt", 0, 1); break; }
	case 3:
	{loot = new Boots("Quick Boots", 1, 0); break; }
	case 4:
	{loot = new Helmet("Helm of Suffering", 5, 1, 1); break; }
	case 5:
	{loot = new Ring("Fancy Ring", 2, 0, 1, 0, 1); break; }
	case 6:
	{loot = new Sheild("Sheild of Blocking", 3); break; }
	case 7:
	{loot = new Weapons("Sword of Pummeling", 1, 1); break; }
	default:
	{	loot = NULL; 
		delete loot;
		cout << "No Items Here" << endl; }
	}
	treasureItems[0] = loot;
}

//! method to display the chest contents
void Treasure::display() {
	cout << "CHEST CONTENTS:" << endl;
	for (int i = 0; i < treasureItems.size(); i++) {

		if (treasureItems.at(i) == NULL) {
			continue;
		}
		if (treasureItems.at(i) != NULL) {
			cout << "Item #" << (i + 1) << " " << treasureItems[i]->getItemName() << endl;
		}

	}
}




