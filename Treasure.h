//! A container class that contains a random object that the character can loot

#pragma once
#include "gfx.h"
#include <vector>
using namespace std;

class Treasure
{
private:

	//! A Vector container to hold the item;
	std::vector <Item*> treasureItems = std::vector <Item*>(1);
	
	//! an item to be looted
	Item* loot = NULL;
public:

	//! A defualt constructor
	Treasure();

	//! A destructor
	~Treasure();

	//! A method that allows a character to pick up an item
	Item* getItemFromTreasure();

	//! A method to display random items
	void setTreasureContents();

	//! A method to display the treasure contents
	void display();

	

};

