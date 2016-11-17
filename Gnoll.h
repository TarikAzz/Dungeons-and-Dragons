#pragma once
#include "Character.h"
#include <string>
#include <afx.h>
using namespace std;

class Gnoll: public Character {
public:
	Gnoll();
	~Gnoll();
	Gnoll(int lvl);
	int giveHeroExp() { return getExpPoints(); };
private:
	string name = "Gnoll";
};