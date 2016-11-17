#pragma once
#include "Character.h"
#include <string>
#include <afx.h>
using namespace std;

class Ogre: public Character {
public:
	Ogre();
	~Ogre();
	Ogre(int lvl);
	int giveHeroExp() { return getExpPoints(); };
private:
	string name = "Ogre";
};