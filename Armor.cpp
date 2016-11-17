//! Creates an Armor object where the character can wear

#include "Armor.h"


//! Default constructor that takes initalizes default values
Armor::Armor()
{
	setItemName("");
	setArmorClass(0);
	setItemID(0);

}

//! Constructor that can take explicit values and create a unique item
Armor::Armor(std::string armorName, int armorBonus) {
	setItemName(armorName);
	setArmorClass(armorBonus);
	setItemID(0);
}

//! Destructor
Armor::~Armor()
{
}
