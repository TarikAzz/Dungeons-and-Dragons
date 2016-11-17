#pragma once
//! Class for all different types of items in the games
//! Included are libraries needed for strings, i/o, and Serialization
#include <string>
#include <iostream>
#include <afx.h>

using namespace std;




class Item : public CObject
{

private:

	//! Instance Variables for enchantments
	std::string itemName;
	int armorClass;
	int strengthEnchantment;
	int constitutionEnchantment;
	int wisdomEnchantment;
	int IQenchantment;
	int charismaEnchantment;
	int dexterityEnchantment;

	int damageBonus;
	int attackBonus;

	int itemID;

	
public:


	Item();
	Item(std::string name, int armor, int strength, int constitution, int dexterity, int charisma, int IQ, int wisdom, int itemID);
	Item(int x);
	virtual ~Item();

	//!Setters & Getters for enchantments
	void setItemName(std::string setName);
	std::string getItemName();
	
	//!Setters & Getters for armor
	void setArmorClass(int setArmor);
	int getArmorClass() { return armorClass; };

	//!Setters & Getters for enchantments
	void setStrengthMod(int setStrength);
	int getStrengthMod() { return strengthEnchantment; };
	
	//!Setters & getters for constituion mod
	void setConstitutionMod(int setConst);
	int getConstitutionMod(){return constitutionEnchantment;};

	//!setters & getters for wisdom mod
	void setWisdomMod(int setWisdom);
	int getWisdomMod() { return wisdomEnchantment; };

	//!setters&getters for Intelligence MOd
	void setIQMod(int setIQ);
	int getIQMod() { return IQenchantment; };
	
	//! Setters & getters for Charisma mod
	void setCharismaMod(int setCharisma);
	int getCharismaMod() { return charismaEnchantment; };

	//!Setters & getters for Dexterity Mod
	void setDexterityMod(int setDexterity);
	int getDexterityMod() { return dexterityEnchantment; };

	
	//! Display the items stats
	void display();

	//!Setters & getters for Weapon bonus
	int getAttackBonus() { return attackBonus; };
	void setAttackBonus(int attack);
	
	//!setters & getters for Damage bonus
	int getDamageBonus() { return damageBonus; };
	void setDamageBonus(int damage);

	//!Setters & Getters for itemID
	int getItemID();
	void setItemID(int setID);

	

	//! Method to Serialize
	void Serialize(CArchive& archive);
	
	//!Operator Overlad method
	friend ostream& operator<<(ostream&, const Item&);
	//! Method that lets the user create an object
	Item* itemCreation();
	
protected:
	//! Declare the Item for Serialization
	DECLARE_SERIAL(Item)
};

