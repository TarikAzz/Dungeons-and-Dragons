#pragma once
#include "Weapon.h"
class Dagger : public Weapon
{
public:
	Dagger();
	
	~Dagger();

	int determineDamage();
	int getDamage();
	void setDamage(int setDamage);
	void display();
private:

	int daggerDamage;
	
};

