//! Class that creates a blet object that the character can wear

#include "Belt.h"


//! Default constructor that iniializes defualt values
Belt::Belt()
{
	setItemName("");
	setConstitutionMod(0);
	setStrengthMod(0);
	setItemID(1);

}

//! Constructor that takes explicit values that can create a unique item
Belt::Belt(std::string beltName, int constitMod, int strengthMod) {
	setItemName(beltName);
	setConstitutionMod(constitMod);
	setStrengthMod(strengthMod);
	setItemID(1);
}

//! a Destructor
Belt::~Belt()
{
}
