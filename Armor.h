//! An armor class that creates an armor object where the character can wear
#pragma once
#include "Item.h"

//! Child class of the Item Class
class Armor : public Item
{
public:

	//!Default Constructor
	Armor();

	//! Constructor that can take explicit values
	Armor(std::string armorName, int armorBonus);
	~Armor();
};

