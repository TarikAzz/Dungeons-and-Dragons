//! @file 
//! Character class header file. 
//! @author Vance De Waele - 25149436
//! This header file lists the various members and attributes of the Character class.
//! Please note that some important information is given regarding the content of certain arrays
//! in this header.

#pragma once
#include "Subject.h"

using namespace std;

class Character : public Subject {
public:
	//! A constructor.
	//!	Randomly generates the Ability Scores while still taking in a level
	//! \param integer lvl to determine the level
	Character(int lvl);
	
	//! A destructor.
	~Character();
	
	//! A constructor.
	//!	Takes in 7 integers - level and 6 dice scores.
	//! \param int lvl to determine the level
	//! \param int s to determine strength
	//! \param int d to determine dexterity
	//! \param int c to determine constitution
	//! \param int i to determine intelligence
	//! \param int w to determine wisdom
	//! \param int h to determine charisma
	Character(int lvl, int s, int d, int c, int i, int w, int h);
	
	//! Setter to set strength
	//! \param int to determine strength
	void setStrength(int);
	
	//! Setter to set dexterity
	//! \param int to determine dexterity
	void setDexterity(int);
	
	//! Setter to set constituion
	//! \param int to determine constitution
	void setConstitution(int);
	
	//! Setter to set intelligence
	//! \param int to determine intelligence
	void setIntelligence(int);
	
	//! Setter to set wisdom
	//! \param int to determine wisdom
	void setWisdom(int);
	
	//! Setter to set charisma
	//! \param int to determine charisma
	void setCharisma(int);
	
	//! Setter to set experience points
	//! \param int which represents the level of the character
	void setExpPoints(int);
	
	//! Method to display the various attributes of the character
	//! \return Displays attributes
	void getScores();
	
	//! Method to return the hit points of a character.
	//! \return hitPoints attribute
	int getHitPoints();
	
	//! Method to return the experience points of a character.
	//! \return expPoints attribute
	int getExpPoints();
	
	//! Method to return the level of a character.
	//! \return level attribute
	int getLevel();
	
	//! Method to determine the validity of a character.
	//! \return boolean that states validity of a character.
	bool isValidCharacter();
	
	//! Method to set the modifiers of a character.
	//! \param int[] of dice rolls (heroAbility)
	void setModifiers(int[]);
	
	//! Method to modify the hit points of a character post-attack.
	//! \param int representing the damage taken by a character.
	void getHit(int);
	
private:
	int level;//! Represents the level of a character
	int hitPoints;//! Represents the hit points of a character
	int expPoints;//! Represents the experience points of a character
	int armorClass;//! Representes the armor class of a character
	int attackBonus;//! Represents the attack bonus of a character
	int damageBonus;//! Represents the damage bonus of a character
	int heroAbility[6];//! 0:Strength; 1:Dexterity; 2:Constitution; 3:Intelligence; 4:Wisdom; 5:Charisma
	int heroModifiers[6];//! Modifiers for each of the ability scores. Indices represent same traits as heroAbilityScores
	int backpack[7];//! 0:Helmet; 1:Armor; 2:Shield; 3:Ring; 4:Belt; 5:Boots; 6:Weapon; currently just a placholder
	
};