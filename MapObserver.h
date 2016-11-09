//!@file
//!@brief Watcher class header file.
//!@author Brandon Amyot - 26990940
//!This watcher class CharacterObserver updates the subject when it received the notify call.
#pragma once

#include "Observer.h"
#include "Map.h"

class MapObserver : public Observer {
public:
	MapObserver();
	MapObserver(Map* m);
	~MapObserver();
	void Update();
	void Display();
	//int GetLevel();
	//bool isAlive();

private:
	Map *_subject;
};
