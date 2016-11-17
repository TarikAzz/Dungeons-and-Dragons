//! @file 
//! @author Vance De Waele - 25149436
//! Implementation of the Character class. Included a few methods to implement
//! the Observer Pattern (Concrete Subject).Notably allowing the necessary 
//! methods to update the observer object. This class is considered the subject.
//! Included the Character.h header file (by extension, the Subject class) 
//! and iostream. No more was necessary.

#include <iostream>
#include "Character.h"
#include "Item.h"
#include <afx.h>
#include <cstddef>
using namespace std;
IMPLEMENT_SERIAL(Character, CObject, 1);

//! Default necessary for Serialization
Character::Character() {
	name = "";
	level = 0;
	setExpPoints(1);
	setStrength(0);
	setDexterity(0);
	setConstitution(0);
	setIntelligence(0);
	setWisdom(0);
	setCharisma(0);
	setHitPoints(10 + heroModifiers[2]); //! Using 10hp as base + Constitution modifier
	setArmorClass();
	setAttackBonus();//! Assuming melee weapon with no finesse property
	setDamageBonus();
	setItems();
}
//! Random constructor. Sets ability scores randomly. The only input is the desired level
//! of a character.
Character::Character(int lvl) {
	name = "Rando the Randomizer";
	level = lvl;
	setExpPoints(lvl);
	setStrength(rand() % 16 + 3);
	setDexterity(rand() % 16 + 3);
	setConstitution(rand() % 16 + 3);
	setIntelligence(rand() % 16 + 3);
	setWisdom(rand() % 16 + 3);
	setCharisma(rand() % 16 + 3);
	setHitPoints(10 + heroModifiers[2]); //! Using 10hp as base + Constitution modifier
	setArmorClass();
	setAttackBonus();//! Assuming melee weapon with no finesse property
	setDamageBonus();
	setItems();
}
//! Constructor that takes 7 integers (provided by dice roll and inputted level) & assigns them
//! to the ability scores for the hero. The modifiers are calculated with the rule that
//! they are equal to the (score-10)/2 and rounding down (taken care of by int divivsion)
Character::Character(string givenName, int lvl, int s, int d, int c, int i, int w, int h) {
	name = givenName;
	level = lvl;
	setExpPoints(lvl);
	setStrength(s);
	setDexterity(d);
	setConstitution(c);
	setIntelligence(i);
	setWisdom(w);
	setCharisma(h);
	setHitPoints(10 + heroModifiers[2]); //! Using 10hp as base + Constitution modifier
	setArmorClass();
	setAttackBonus();//! Assuming melee weapon with no finesse property
	setDamageBonus();
	setItems();
}
Character::~Character() {
	for (int i = 0; i < 7; i++) {
		delete backPack[i];
		backPack[i] = NULL;
	}
	for (int i = 0; i < 7; i++) {
		delete equippedItems[i];
		equippedItems[i] = NULL;
	}
}

void Character::setStrength(int s) {
	heroAbility[0] = s;
	heroModifiers[0] = (s - 10) / 2;
}
void Character::setDexterity(int d) {
	heroAbility[1] = d;
	heroModifiers[1] = (d - 10) / 2;
}
void Character::setConstitution(int c) {
	heroAbility[2] = c;
	heroModifiers[2] = (c - 10) / 2;
}
void Character::setIntelligence(int i) {
	heroAbility[3] = i;
	heroModifiers[3] = (i - 10) / 2;
}
void Character::setWisdom(int w) {
	heroAbility[4] = w;
	heroModifiers[4] = (w - 10) / 2;
}
void Character::setCharisma(int h) {
	heroAbility[5] = h;
	heroModifiers[5] = (h - 10) / 2;
}
void Character::setItems() {
	for (int i = 0; i < 7; i++)
		equippedItems[i] = new Item(i);
	for (int i = 0; i < 7; i++)
		backPack[i] = new Item(0);
}

//! Currently implementing levels 1 to 5. Will add coding for higher levels in the future.
void Character::setExpPoints(int lvl) {
	switch (lvl) {
	case 1: expPoints = 0; break;
	case 2:	expPoints = 300; break;
	case 3:	expPoints = 900; break;
	case 4:	expPoints = 2700; break;
	case 5:	expPoints = 6500; break;
	case 6:	expPoints = 14000; break;
	case 7:	expPoints = 23000; break;
	case 8:	expPoints = 34000; break;
	case 9:	expPoints = 48000; break;
	case 10: expPoints = 64000; break;
	case 11: expPoints = 85000; break;
	case 12: expPoints = 100000; break;
	case 13: expPoints = 120000; break;
	case 14: expPoints = 140000; break;
	case 15: expPoints = 165000; break;
	case 16: expPoints = 195000; break;
	case 17: expPoints = 225000; break;
	case 18: expPoints = 265000; break;
	case 19: expPoints = 305000; break;
	case 20: expPoints = 355000; break;
	default:
		cout << "Error in creating character";
		exit(1);
	}
}
//! Method that checks if the character is valid.
bool Character::isValidCharacter() {
	for (int i = 0; i <= 5; i++) {
		if (heroAbility[i] < 3 || heroAbility[i]>18)
			return false;
	}
	return true;
}
//! Method that allows a character to receive a hit, modifying its hit points
//! New feature: method now notifies the observer. Identified in code below.
void Character::receiveAttack(int hit) {
	hitPoints = hitPoints - hit;
	Notify(); //Subject method

}
void Character::Serialize(CArchive& archive) {
	CObject::Serialize(archive);

	if (archive.IsStoring()) {
		archive << level;
		archive << hitPoints;
		archive << expPoints;
		archive << armorClass;
		archive << attackBonus;
		archive << damageBonus;
		for (int i = 0; i < 6; i++) {
			archive << heroAbility[i];
		}
		for (int i = 0; i < 6; i++) {
			archive << heroModifiers[i];
		}
		/*for (int i = 0; i < 7; i++) {
			archive << backPack[i];
		}
		for (int i = 0; i < 7; i++) {
			archive << equippedItems[i];
		}*/

	}
	else {
		CString csName;
		archive >> csName;
		CT2CA pszConvertedAnsiString(csName);
		std::string strStd(pszConvertedAnsiString);
		name = strStd;

		archive >> level;
		archive >> hitPoints;
		archive >> expPoints;
		archive >> armorClass;
		archive >> attackBonus;
		archive >> damageBonus;
		for (int i = 0; i < 6; i++) {
			archive >> heroAbility[i];
		}
		for (int i = 0; i < 6; i++) {
			archive >> heroModifiers[i];
		}
		/*for (int i = 0; i < 7; i++) {
			archive >> backPack[i];
		}*/
		/*for (int i = 0; i < 7; i++) {
			archive >> equippedItems[i];
		}*/
	}

}

//! Simple method used in the driver to output the properties of a character including
//! modifiers that are determined by the scores entered or generated.
void Character::getScores() {
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl; // Name output needed
	cout << "Hit Points: \t" << hitPoints << endl;
	cout << "Experience: \t" << expPoints << endl;
	cout << "Strength: \t" << heroAbility[0] << "\tModifier: " << heroModifiers[0] << endl;
	cout << "Deterity: \t" << heroAbility[1] << "\tModifier: " << heroModifiers[1] << endl;
	cout << "Constitution: \t" << heroAbility[2] << "\tModifier: " << heroModifiers[2] << endl;
	cout << "Intelligence: \t" << heroAbility[3] << "\tModifier: " << heroModifiers[3] << endl;
	cout << "Wisdom: \t" << heroAbility[4] << "\tModifier: " << heroModifiers[4] << endl;
	cout << "Charisma: \t" << heroAbility[5] << "\tModifier: " << heroModifiers[5] << endl;
}
ostream& operator<<(ostream& out, Character& buddy)
{
	out << "Name: " << buddy.getName() << endl;
	out << "Level: " << buddy.getLevel() << endl;
	out << "Hit Points: \t" << buddy.getHitPoints() << endl;
	out << "Experience: \t" << buddy.getExpPoints() << endl;
	out << "Strength: \t" << buddy.getStrength() << "\tModifier: " << buddy.getModifier(0) << endl;
	out << "Deterity: \t" << buddy.getDexterity() << "\tModifier: " << buddy.getModifier(1) << endl;
	out << "Constitution: \t" << buddy.getConstitution() << "\tModifier: " << buddy.getModifier(2) << endl;
	out << "Intelligence: \t" << buddy.getIntelligence() << "\tModifier: " << buddy.getModifier(3) << endl;
	out << "Wisdom: \t" << buddy.getWisdom() << "\tModifier: " << buddy.getModifier(4) << endl;
	out << "Charisma: \t" << buddy.getCharisma() << "\tModifier: " << buddy.getModifier(5) << endl;
	return out;
}
void Character::addToInventory(Item* item) {
	int i = 0;
	while (backPack[i]->getItemName() != "Nothing") {
		i++;
		if (i >= 7)
			cout << "No more room!";
	}
	backPack[i] = item;
}

void Character::equipInventory() {
	int index;
	cout << "ENTER THE ITEM # YOU WANT TO EQUIP" << endl;
	displayInventory();
	cin >> index;
	if (index == 0 || index > 7) {
		cout << "Item Does not Exist" << endl;
		return;
	}
	equipItem(backPack[index - 1]);
	delete backPack[index - 1];
	backPack[index - 1] = NULL;
}

void Character::displayInventory() {
	cout << "YOU HAVE THE FOLLOWING ITEMS IN YOUR BACKPACK:" << endl;
	for (int i = 0; i < 7; i++) {
		if (equippedItems[i] == nullptr) {
			continue;
		}
		cout << "SLOT #" << (i + 1) << " " << equippedItems[i]->getItemName() << endl;
	}
}
void Character::equipItem(Item* item) {
	int itemID = item->getItemID();
	switch (itemID) {
	case 0: equippedItems[0] = item; break;
	case 1: equippedItems[1] = item; break;
	case 2: equippedItems[2] = item; break;
	case 3: equippedItems[3] = item; break;
	case 4: equippedItems[4] = item; break;
	case 5: equippedItems[5] = item; break;
	case 6: equippedItems[6] = item; break;
	default: cout << "Invalid Item" << endl;
	}
}
void Character::removeItem() {
	int index;
	cout << "ENTER THE ITEM NUMBER YOU WOULD LIKE TO REMOVE:" << endl;
	displayWornItems();
	cin >> index;
	if (index == 0 || index > 7) {
		cout << "ITEM DOES NOT EXIST" << endl;
		return;
	}
	delete equippedItems[index - 1];
	equippedItems[index - 1] = NULL;

}
void Character::displayWornItems() {
	cout << "YOU ARE WEARING THE FOLLOWING ITEMS:" << endl;
	for (int i = 0; i < 7; i++) {
		if (equippedItems[i] == nullptr) {
			continue;
		}
		cout << "SLOT #" << (i + 1) << " " << equippedItems[i]->getItemName() << endl;
	}
}