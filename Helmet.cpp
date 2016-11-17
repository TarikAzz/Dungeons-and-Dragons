//! Creates a Helmet Object that the character can wear

#include "Helmet.h"


//! Defualt consturctor that takes initial values
Helmet::Helmet()
{
	setItemName("");
	setArmorClass(0);
	setIQMod(0);
	setWisdomMod(0);
	setItemID(3);
}

//! Constructor that takes explicit values to create a uniqe item
Helmet::Helmet(std::string helmetName, int helmetBonus, int IQMod, int wisdomMod) {
	setItemName(helmetName);
	setArmorClass(helmetBonus);
	setIQMod(IQMod);
	setWisdomMod(wisdomMod);
	setItemID(3);
}


//! Destructor
Helmet::~Helmet()
{
}
