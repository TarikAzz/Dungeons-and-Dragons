//! Implementation file for the boots class

#include "Boots.h"


//! Default constructor that takes initial values
Boots::Boots()
{
	setItemName("");
	setArmorClass(0);
	setDexterityMod(0);
	setItemID(2);
}

//! Constructor that takes explicit values to create a unique item
Boots::Boots(std::string bootsName, int bootArmorBonus, int dexMod) {
	setItemName(bootsName);
	setArmorClass(bootArmorBonus);
	setDexterityMod(dexMod);
	setItemID(2);
}
//! A Destructor

Boots::~Boots()
{
}
