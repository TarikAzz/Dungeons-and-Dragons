//!@file
//!@brief Implementation of watcher class.
//!@author Brandon Amyot - 26990940
//!This watcher class CharacterObserver updates the subject when it received the notify call.

#include "CharacterObserver.h"
#include "Character.h"
#include <iostream>
using namespace std;

CharacterObserver::CharacterObserver() {	
};
CharacterObserver::CharacterObserver(Character* ch) {
	_subject = ch;
	_subject->Attach(this);
};
CharacterObserver::~CharacterObserver() {
	//Upon destruction, detaches itself from its Character      
	_subject->Detach(this);
};
void CharacterObserver::Update() {
	Display();
};
void CharacterObserver::Display() {
	_subject->getScores();
};
int CharacterObserver::GetLevel() {
	return _subject->getLevel();
};
bool CharacterObserver::isAlive() {
	if (_subject->getHitPoints() > 0)
		return true;
	else
		return false;
}