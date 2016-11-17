//! @file 
//! @author Vance De Waele - 25149436
//! Character class header file. Updated to inherit from Subject class.
//! As such, it now imports Subject.h
//! This header file lists the various members and attributes of the Character class.
//! New feature in this version: string name now allows the character to be named.
//! Please note that some important information is given regarding the content of certain arrays
//! in this header.

#pragma once
#include "Subject.h"
#include <string>
#include "gfx.h"
#include <afx.h>
using namespace std;

class Character : public Subject, public CObject {
public:
	//! Default for serialization.
	Character();

	//! A constructor.
	//!	Randomly generates the Ability Scores while still taking in a level
	//! \param integer lvl to determine the level
	Character(int lvl);


	//! A destructor.
	~Character();

	//! A constructor.
	//!	Takes in a string, 7 integers - level and 6 dice scores.
	//! \param string name to set the character's name
	//! \param int lvl to determine the level
	//! \param int s to determine strength
	//! \param int d to determine dexterity
	//! \param int c to determine constitution
	//! \param int i to determine intelligence
	//! \param int w to determine wisdom
	//! \param int h to determine charisma
	Character(string name, int lvl, int s, int d, int c, int i, int w, int h);

	//! Setter to set strength and its modifier
	//! \param int to determine strength
	void setStrength(int s);
	//! Setter to set dexterity and its modifier
	//! \param int to determine dexterity
	void setDexterity(int d);
	//! Setter to set constituion and its modifier
	//! \param int to determine constitution
	void setConstitution(int c);
	//! Setter to set intelligence and its modifier
	//! \param int to determine intelligence
	void setIntelligence(int i);
	//! Setter to set wisdom and its modifier
	//! \param int to determine wisdom
	void setWisdom(int w);
	//! Setter to set charisma and its modifier
	//! \param int to determine charisma
	void setCharisma(int h);
	//! Setter to set experience points
	//! \param int which represents the level of the character
	void setExpPoints(int);

	//! Sets a specific number for expPoints
	void setSpecificExp(int exp) { expPoints = exp; };

	//! Method that sets hit points
	void setHitPoints(int health) { hitPoints = health; };
	//! Method that sets level of the character.
	void setLevel(int lvl) { level = lvl; };
	//! Method to set attack bonus.
	void setAttackBonus() { attackBonus = heroModifiers[0]; };
	//! Method to set damage bonus.
	void setDamageBonus() { damageBonus = heroModifiers[0]; };
	//! Method to set armor class.
	void setArmorClass() { armorClass = 10 + heroModifiers[1]; };

	void setArmorClass(int arm) { armorClass = arm; };

	//! Method to display the various attributes of the character
	//! \return Displays attributes
	void getScores();


	int getStrength() { return heroAbility[0]; };

	int getDexterity() { return heroAbility[1]; };

	int getConstitution() { return heroAbility[2]; };

	int getIntelligence() { return heroAbility[3]; };

	int getWisdom() { return heroAbility[4]; };

	int getCharisma() { return heroAbility[5]; };

	int getModifier(int x) { return heroModifiers[x]; };
	//! Method to return the hit points of a character.
	//! \return hitPoints attribute
	int getHitPoints() { return hitPoints; };

	//! Method to return the experience points of a character.
	//! \return expPoints attribute
	int getExpPoints() { return expPoints; };

	//! Method to return the level of a character.
	//! \return level attribute
	int getLevel() { return level; };

	//! Method to return the name of the Character created.
	//! \return name attribute
	string getName() { return name; };

	//! Method to determine the validity of a character.
	//! \return boolean that states validity of a character.
	bool isValidCharacter();

	//! Method to modify the hit points of a character post-attack.
	//! Please note that this method was renamed from 'getHit' to avoid confusion.
	//! \param int representing the damage taken by a character.
	void receiveAttack(int);

	void Character::setItems();
	void Character::addToInventory(Item* item);
	void Character::displayInventory();
	void Character::equipInventory();
	void Character::equipItem(Item* item);
	void Character::removeItem();
	void Character::displayWornItems();

	//! Necessary for Serialization of the class.
	void Serialize(CArchive& archive);
	//! Necessary for Serialization of the class.
	friend ostream& operator<<(ostream&, const Character&);

private:
	string name;//! String to represent the name of a character.
	int level;//! Represents the level of a character
	int hitPoints;//! Represents the hit points of a character
	int expPoints;//! Represents the experience points of a character
	int armorClass;//! Representes the armor class of a character
	int attackBonus;//! Represents the attack bonus of a character
	int damageBonus;//! Represents the damage bonus of a character
	int heroAbility[6];//! 0:Strength; 1:Dexterity; 2:Constitution; 3:Intelligence; 4:Wisdom; 5:Charisma
	int heroModifiers[6];//! Modifiers for each of the ability scores. Indices represent same traits as heroAbilityScores
	Item* backPack[7];
	Item* equippedItems[7]; //! 0:Helmet; 1:Armor; 2:Shield; 3:Ring; 4:Belt; 5:Boots; 6:Weapon;

protected:
	DECLARE_SERIAL(Character)
};