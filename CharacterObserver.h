//!@file
//!@brief Watcher class header file.
//!@author Brandon Amyot - 26990940
//!This watcher class CharacterObserver updates the subject when it received the notify call.
#pragma once

#include "Observer.h"
#include "Character.h"

class CharacterObserver : public Observer {
public:
	CharacterObserver();
	CharacterObserver(Character* ch);
	~CharacterObserver();
	void Update();
	void Display();
	int GetLevel();
	bool isAlive();

private:
	Character *_subject;
};
