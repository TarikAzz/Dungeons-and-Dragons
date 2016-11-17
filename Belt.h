//! A class that creates a belt object that the character can wear
#pragma once
#include "Item.h"

//! A subclass of the Item Class
class Belt : public Item
{
public:
	//! A defualt constructor
	Belt();

	//! A constructor that takes initialvalues to make a unique item
	Belt(std::string beltName, int constitMod, int strengthMod);
	~Belt();
};

