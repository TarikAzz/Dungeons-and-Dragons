#pragma once
#include "Character.h"
#include "Ogre.h"
using namespace std;

Ogre::Ogre(){
	setLevel(1);
	setSpecificExp(450);
	setStrength(0);
	setDexterity(0);
	setConstitution(0);
	setIntelligence(0);
	setWisdom(0);
	setCharisma(0);
	setHitPoints(10);
	setArmorClass(10);
	setAttackBonus();
	setDamageBonus();
}

Ogre::Ogre(int lvl) {
	setLevel(lvl);
	setSpecificExp(450);
	setStrength(19);
	setDexterity(8);
	setConstitution(16);
	setIntelligence(5);
	setWisdom(7);
	setCharisma(7);
	setHitPoints(59);
	setArmorClass(11);
	setAttackBonus();
	setDamageBonus();
}
Ogre::~Ogre() {}