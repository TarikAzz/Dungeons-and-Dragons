#pragma once
#include <string>
#include "dice.h"
#include "Item.h"

class Weapons :public Item
{
public:
	Weapons();
	Weapons(std::string name, int attackMod, int damageMod);
	~Weapons();

	int determineDamage();
	
	

	
	
private:
	int damage;
	int attackBonus;

	

};

