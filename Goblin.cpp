#pragma once
#include "Character.h"
#include "Goblin.h"
#include <string>
#include <afx.h>
using namespace std;

Goblin::Goblin(){
	setLevel(1);
	setSpecificExp(50);
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

Goblin::Goblin(int lvl) {
	setLevel(lvl);
	setSpecificExp(50);
	setStrength(8);
	setDexterity(14);
	setConstitution(10);
	setIntelligence(10);
	setWisdom(8);
	setCharisma(8);
	setHitPoints(7);
	setArmorClass(15);
	setAttackBonus();
	setDamageBonus();
}
Goblin::~Goblin() {}