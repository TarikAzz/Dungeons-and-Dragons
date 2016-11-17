//! A Class to create a ring object that the character can wear

#pragma once
#include "Item.h"

//! A subclass of the items
class Ring : public Item
{
public:
	//!A defualt construcstor
	Ring();

	//! A constructor that takes explicit values to create a unique item
	Ring(std::string ringName, int ringArmorBonus, int strengthMod, int constitMod, int wisdomMod, int charismaMod);
	
	//A Destructor
	~Ring();
};

