#pragma once
#include "Character.h"
#include "Gnoll.h"
using namespace std;

Gnoll::Gnoll(){
	setLevel(1);
	setSpecificExp(100);
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

Gnoll::Gnoll(int lvl) {
	setLevel(lvl);
	setSpecificExp(100);
	setStrength(14);
	setDexterity(12);
	setConstitution(11);
	setIntelligence(6);
	setWisdom(10);
	setCharisma(7);
	setHitPoints(22);
	setArmorClass(15);
	setAttackBonus();
	setDamageBonus();
}
Gnoll::~Gnoll() {}