#include "Ring.h"



Ring::Ring()
{
	setItemName("");
	setArmorClass(0);
	setStrengthMod(0);
	setConstitutionMod(0);
	setWisdomMod(0);
	setCharismaMod(0);
	setItemID(4);
}

Ring::Ring(std::string ringName, int ringArmorBonus, int strengthMod, int constitMod, int wisdomMod, int charismaMod) {
	setItemName(ringName);
	setArmorClass(ringArmorBonus);
	setStrengthMod(strengthMod);
	setConstitutionMod(constitMod);
	setWisdomMod(wisdomMod);
	setCharismaMod(charismaMod);
	setItemID(4);
}


Ring::~Ring()
{
}
