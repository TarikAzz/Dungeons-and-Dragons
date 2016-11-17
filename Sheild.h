//! A class to create a sheild object that the character can wear
#pragma once
#include "Item.h"

//! A subclass of the items
class Sheild : public Item
{
public:

	//!A defualt construcstor
	Sheild();

	//! A constructor that takes explicit values to create a unique item
	Sheild(std::string sheildName, int sheildBonus);
	
	//A Destructor
	~Sheild();
};

