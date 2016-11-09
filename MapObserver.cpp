//!@file
//!@brief Implementation of watcher class.
//!@author Brandon Amyot - 26990940
//!This watcher class CharacterObserver updates the subject when it received the notify call.

#include "MapObserver.h"
#include "Map.h"
#include <iostream>
using namespace std;

MapObserver::MapObserver() {	
};
MapObserver::MapObserver(Map* m) {
	_subject = m;
	_subject->Attach(this);
};
MapObserver::~MapObserver() {
	//Upon destruction, detaches itself from its Character      
	_subject->Detach(this);
};
void MapObserver::Update() {
	Display();
};
void MapObserver::Display() {
	_subject->printMap();
};

//int CharacterObserver::GetLevel() {
//	return _subject->getLevel();
//};
//bool CharacterObserver::isAlive() {
//	if (_subject->getHitPoints() > 0)
//		return true;
//	else
//		return false;
//}