//! @file 
//! @author Vance De Waele - 25149436
//! Watcher class header file. Inherits from Observer class. 
//! This header file lists the various members and attributes of the Watcher class.
//! This class serves as a concrete implementation of the Observer class. It imports 
//! both the Observer.h and Character.h files to allow it to use both in its part
//! of the Observer Pattern.

#pragma once
#include "Observer.h"
#include "Character.h"
using namespace std;

//! Class is a sub class of Observer
class Watcher : public Observer {
public:
	//! Default Constructor.
	Watcher();
	//! Constructor that takes in a Character pointer
	Watcher(Character* hero);
	//! Basic destructor
	~Watcher();
	//! Method that updates the Observer with information from the Character(subject) class. 
	void Update();
	//! Method that displays information contained in the Character object observed
	void Display();
	//! Method used to obtain information about a Character object's level
	int findOutLevel();
	//! Method used to determined whether an observed Character object has hit points above 0.
	int characterIsDead();
	Character* createHero();
private:
	//! Pointer to a Character object, serves to reference the observed Character.
	Character *_subject;
};

