#pragma once
#include "Character.h"
using namespace std;

class Goblin: public Character {
public:
	Goblin();
	~Goblin();
	Goblin(int lvl);
	int giveHeroExp() { return getExpPoints(); };
private:
	string name = "Goblin";
};