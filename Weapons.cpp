//! Class to create a weapion

#include "Weapons.h"


//! Default constructor
Weapons::Weapons()
{
	setItemName("No Name");
	setAttackBonus(0);
	setDamageBonus(0);
	setItemID(6);
}

//! Constuctor that takes explicit arguments
Weapons::Weapons(std::string name, int attackMod, int damageMod) {
	setItemName(name);
	setAttackBonus(attackMod);
	setDamageBonus(damageMod);
	setItemID(6);
}


Weapons::~Weapons()
{
}



//! Method to determine the damage y die roll;
int Weapons::determineDamage() {
	Dice dice;

	damage = dice.Roll("1d4");

	return damage;
}