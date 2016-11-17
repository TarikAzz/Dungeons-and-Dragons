//! A class that creates a boots object that the character can wear

#pragma once
#include "Item.h"

//! A subclass of the items
class Boots : public Item
{
public:

	//! A defualt construcstor
	Boots();

	//! A constructor that takes explicit values to create a unique item
	Boots(std::string bootsName, int bootArmorBonus, int dexMod);
	~Boots();
};

