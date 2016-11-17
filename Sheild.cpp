#include "Sheild.h"



Sheild::Sheild()
{
	setItemName("");
	setArmorClass(0);
	setItemID(5);
}

Sheild::Sheild(std::string sheildName, int sheildBonus) {
	setItemName(sheildName);
	setArmorClass(sheildBonus);
	setItemID(5);

}


Sheild::~Sheild()
{
}
