//! @file 
//! Implementation of the Character class. 
//! Included the Character.h header file, iostream. No more was necessary.
//! @author Vance De Waele - 25149436
#include <iostream>
#include "Character.h";
using namespace std;

//! Random constructor. Sets ability scores randomly. The only input is the desired level
//! of a character.
Character::Character(int lvl) {
	level = lvl; 
	setExpPoints(lvl);
	setStrength(rand()%16+3);
	setDexterity(rand()%16+3);
	setConstitution(rand()%16+3);
	setIntelligence(rand()%16+3);
	setWisdom(rand()%16+3);
	setCharisma(rand()%16+3);
	setModifiers(heroAbility);
	hitPoints = 10 + heroModifiers[2]; //! Using 10hp as base + Constitution modifier
	armorClass = 10 + heroModifiers[1];
	attackBonus = heroModifiers[0];//! Assuming melee weapon with no finesse property
	damageBonus = heroModifiers[0];
}
//! Constructor that takes 7 integers (provided by dice roll and inputted level) & assigns them
//! to the ability scores for the hero. The modifiers are calculated with the rule that
//! they are equal to the (score-10)/2 and rounding down (taken care of by int divivsion)
Character::Character(int lvl, int s, int d, int c, int i, int w, int h) {
	level = lvl;
	setExpPoints(lvl);
	setStrength(s);
	setDexterity(d);
	setConstitution(c);
	setIntelligence(i);
	setWisdom(w);
	setCharisma(h);
	setModifiers(heroAbility);
	hitPoints = 10 + heroModifiers[2]; //! Using 10hp as base + Constitution modifier
	armorClass = 10 + heroModifiers[1];
	attackBonus = heroModifiers[0];//! Assuming melee weapon with no finesse property
	damageBonus = heroModifiers[0];
}
Character::~Character() {}

//! Setter for strength attribute
void Character::setStrength(int s) { 
	heroAbility[0] = s; 
	Notify();
}

//! Setter for dexterity attribute
void Character::setDexterity(int d) { 
	heroAbility[1] = d; 
	Notify();
}

//! Setter for constitution attribute
void Character::setConstitution(int c) { 
	heroAbility[2] = c;
	Notify();
}

//! Setter for intelligence attribute
void Character::setIntelligence(int i) { 
	heroAbility[3] = i;
	Notify();
}

//! Setter for wisdon attribute
void Character::setWisdom(int w) { 
	heroAbility[4] = w; 
	Notify();
}

//! Setter for charisma attribute
void Character::setCharisma(int h) { 
	heroAbility[5] = h; 
	Notify();
}

//! Sets the modifiers from the ability scores rolled. Follows the formula that the 
//! modifier is the score-10 divided by 2 and rounded down (rounded by int division).
void Character::setModifiers(int scores[]) {
	heroModifiers[0] = (scores[0] - 10) / 2;
	heroModifiers[1] = (scores[1] - 10) / 2;
	heroModifiers[2] = (scores[2] - 10) / 2;
	heroModifiers[3] = (scores[3] - 10) / 2;
	heroModifiers[4] = (scores[4] - 10) / 2;
	heroModifiers[5] = (scores[5] - 10) / 2;
	Notify();
}
//! Currently implementing levels 1 to 5. Will add coding for higher levels in the future.
void Character::setExpPoints(int lvl) {
	switch (lvl) {
		case 1: 
			expPoints = 0;
			break;
		case 2:
			expPoints = 300;
			break;
		case 3:
			expPoints = 900;
			break;
		case 4:
			expPoints = 2700;
			break;
		case 5:
			expPoints = 6500;
			break;
	}
	Notify();
}
//! Returns the hit points of a character
int Character::getHitPoints() {
	return hitPoints;
}
//! Returns the experience points of a character
int Character::getExpPoints() {
	return expPoints;
}
//! Returns the level of a character.
int Character::getLevel() {
	return level;
}
//! Method that checks if the character is valid.
bool Character::isValidCharacter() {
	for (int i = 0; i <= 5; i++){
	if (heroAbility[i] < 3 || heroAbility[i]>18)
		return false;
	}
	return true;
}
//! Method that allows a character to receive a hit, modifying its hit points
void Character::getHit(int hit) {
	hitPoints = hitPoints - hit;
	Notify();
}

//! Simple method used in the driver to output the properties of a character including
//! modifiers that are determined by the scores entered or generated.
void Character::getScores() {
	cout << "Level: " << level << endl;
	cout << "Hit Points: " << hitPoints << endl;
	cout << "Experience: " << expPoints << endl;
	cout << "Strength: " << heroAbility[0] << "\tModifier: " << heroModifiers[0] << endl;
	cout << "Deterity: " << heroAbility[1] << "\tModifier: " << heroModifiers[1] << endl; 
	cout << "Constitution: " << heroAbility[2] << "\tModifier: " << heroModifiers[2] << endl;
	cout << "Intelligence: " << heroAbility[3] << "\tModifier: " << heroModifiers[3] << endl;
	cout << "Wisdom: " << heroAbility[4] << "\tModifier: " << heroModifiers[4] << endl;
	cout << "Charisma: " << heroAbility[5] << "\tModifier: " << heroModifiers[5] << endl;
}