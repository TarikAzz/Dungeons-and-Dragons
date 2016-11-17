//! Implementation file of Item.cpp
//! Creates an item


#include "Item.h"
#include "gfx.h"

#include <afx.h>

IMPLEMENT_SERIAL(Item, CObject, 1);
// !Default constructor
Item::Item()
{
	this->armorClass = 0;
	this->strengthEnchantment = 0;
	this->constitutionEnchantment = 0;
	this->dexterityEnchantment = 0;
	this->charismaEnchantment = 0;
	this->wisdomEnchantment = 0;
	this->IQenchantment = 0;
	this->itemID = 0;
	
}

//! Constructor that creates a unique item
Item::Item(std::string name, int armor, int strength, int constitution, int dexterity, int charisma, int IQ, int wisdom, int itemID) {
	itemName = name;
	this->armorClass = armor;
	this->strengthEnchantment = strength;
	this->constitutionEnchantment = constitution;
	this->dexterityEnchantment = dexterity;
	this->charismaEnchantment = charisma;
	this->wisdomEnchantment = wisdom;
	this->IQenchantment = IQ;
	this->itemID = itemID;
	
}

Item::Item(int x)
{
	itemName = "Nothing";
	this->armorClass = 0;
	this->strengthEnchantment = 0;
	this->constitutionEnchantment = 0;
	this->dexterityEnchantment = 0;
	this->charismaEnchantment = 0;
	this->wisdomEnchantment = 0;
	this->IQenchantment = 0;
	this->itemID = x;

}
//!Destructor
Item::~Item()
{
}


//! Methods for setting & getting Item Name
void Item::setItemName(std::string setName) {
	itemName = setName;
}
std::string Item::getItemName() {
	return itemName;
}

//! Methods for setting & Getting Armor class
void Item::setArmorClass(int setArmor) {
	armorClass = setArmor;
}



//! Methods for setting & getting Strength mod
void Item::setStrengthMod(int setStrength) {
	strengthEnchantment = setStrength;
}


//! Methods for setting & getting constitution mod
void Item::setConstitutionMod(int setConst) {
	constitutionEnchantment = setConst;
}



//! Methods for setting & getting wisdom mod
void Item::setWisdomMod(int setWisdom) {
	wisdomEnchantment = setWisdom;
}


//! Methods for setting & getting IQ mod
void Item::setIQMod(int setIQ) {
	IQenchantment = setIQ;
}



//!Methods for setting & getting Charisma mod
void Item::setCharismaMod(int setCharisma) {
	charismaEnchantment = setCharisma;
}


//!Methods for setting & getting Dexterity mod
void Item::setDexterityMod(int setDexterity) {
	dexterityEnchantment = setDexterity;
}

//!Method for setting Attack bonus
void Item::setAttackBonus(int attack) {
	attackBonus = attack;
}

//! Method for setting Attack bonus
void Item::setDamageBonus(int damage) {
	damageBonus = damage;
}



//! SERIALIZE method to store/load an iteam object

void Item::Serialize(CArchive& archive) {
	CObject::Serialize(archive);
	if (archive.IsStoring()) {
		archive << CString(itemName.c_str());
		archive << armorClass;
		archive << strengthEnchantment;
		archive << constitutionEnchantment;
		archive << wisdomEnchantment;
		archive << IQenchantment;
		archive << charismaEnchantment;
		archive << dexterityEnchantment;
		archive << itemID;

	}
	else {
		CString csItemName;
		archive >> csItemName;
		CT2CA pszConvertedAnsiString(csItemName);
		std::string strStd(pszConvertedAnsiString);
		itemName = strStd;
		
		
		archive >> armorClass;
		archive >> strengthEnchantment;
		archive >> constitutionEnchantment;
		archive >> wisdomEnchantment;
		archive >> IQenchantment;
		archive >> charismaEnchantment;
		archive >> dexterityEnchantment;
		archive >> itemID;
	}
}


//! method to display item characteristics
void Item::display() {
	cout << "Item Name: " << itemName << endl;
	cout << "Armor: " << armorClass << endl;
	cout << "Strength Enchantment: " << strengthEnchantment << endl;
	cout << "Constitution Enchantment: " << constitutionEnchantment << endl;
	cout << "Wisdom Enchantment: " << wisdomEnchantment << endl;
	cout << "Intelligence Enchantment: " << IQenchantment << endl;
	cout << "Charisma Enchantment: " << charismaEnchantment << endl;
	cout << "Dexterity Enchantment: " << dexterityEnchantment << endl;

}

//! Operator overload friend function for output
ostream& operator<<(ostream& out, Item& friendo) {
	out << "Item Name: " << friendo.getItemName() << endl;
	out << "Armor: " << friendo.getArmorClass() << endl;
	out << "Strength Enchantment: " << friendo.getStrengthMod() << endl;
	out << "Constitution Enchantment: " << friendo.getConstitutionMod() << endl;
	out << "Wisdom Enchantment: " << friendo.getWisdomMod() << endl;
	out << "Intelligence Enchantment: " << friendo.getIQMod() << endl;
	out << "Charisma Enchantment: " << friendo.getCharismaMod() << endl;
	out << "Dexterity Enchantment: " << friendo.getDexterityMod() << endl;
	out << "Item ID: " << friendo.getItemID() << endl;
	return out;
}


//! Method for geting ItemID
int Item::getItemID() {
	return itemID;
}

//!Method for setting ITEMID
void Item::setItemID(int setID) {
	itemID = setID;
}

//!Method for a user created Item
Item* Item::itemCreation() {
	cout << "=======================================================================================" << endl;
	cout << "-----------------------------ITEM CREATION MENU----------------------------------------" << endl;
	cout << "=======================================================================================" << endl;


	cout << "Do you Want to Load or Save and Item" << endl;

	std::string choice;
	cin >> choice;


	if (choice == "Save" || choice == "save") {


		std::string fileName;

		cout << "Enter the File Name Where you would like to store the weapon: " << endl;
		cin >> fileName;

		cout << "WHICH ITEM WOULD YOU LIKE TO CREATE: " << endl;
		cout << "#1 Armor" << endl;
		cout << "#2 Sheild" << endl;
		cout << "#3 Weapon" << endl;

		int input;
		cin >> input;

		input = input - 1;

		Item* user = NULL;

		if (input == 0) {

			int armor;
			cout << "ARMOR" << endl;
			cout << "Enter the Amount of ArmorClass: ";

			cin >> armor;

			user = new Armor("SheepSkin Coat", armor);

		}

		else if (input == 1) {

			int armor;
			cout << "SHEILD" << endl;
			cout << "Enter the amout of ArmorClass: ";
			cin >> armor;

			user = new Sheild("Weak Sheild", armor);


		}
		else if (input == 2) {
			int attack;
			int damage;
			cout << "WEAPON" << endl;
			cout << "Enter the Attack Bonus: ";
			cin >> attack;
			cout << "Enter the Damage Bonus: ";
			cin >> damage;

			user = new Weapons("Rusty Blade", attack, damage);

		}
		else {
			cout << "Invalid Input" << endl;
		}

		if (user->getArmorClass() > 2 || user->getAttackBonus() > 2 || user->getDamageBonus() > 2) {
			cout << "This is an invalid item" << endl;
			delete user;
			user = NULL;
		}

		else {

			cout << "Here is your item: \n" << endl;
			user->display();

			CFile saveFile;
			saveFile.Open((CString(fileName.c_str())), CFile::modeCreate | CFile::modeWrite);
			CArchive archive(&saveFile, CArchive::store);
			user->Serialize(archive);


			archive.Close();
			saveFile.Close();
			return user;

		}






	}
	//Assuming perfect input & file name
	else if (choice == "Load" || choice == "load") {

		cout << "Enter the file Name you would like to load" << endl;

		std::string fileInput;

		cin >> fileInput;
		CFile openFile;


		openFile.Open((CString(fileInput.c_str())), CFile::modeRead);
		CArchive otherArchive(&openFile, CArchive::load);

		Item* item2 = new Item();
		item2->Serialize(otherArchive);

		item2->display();


		openFile.Close();
		otherArchive.Close();

		return item2;
	}
}




	