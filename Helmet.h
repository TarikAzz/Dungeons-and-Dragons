//! A class to create a helmet object that the character can wear

#pragma once
#include "Item.h"

//! A subclass of the items
class Helmet : public Item
{
public:
	//!A defualt construcstor
	Helmet();

	//! A constructor that takes explicit values to create a unique item
	Helmet(std::string helmetName, int helmetBonus, int IQMod, int wisdomMod);
	
	//A Destructor
	~Helmet();
};

