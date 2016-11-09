//!@file
//!@brief Subject header file.
//!@author Brandon Amyot - 26990940
//!This Subject class is designed to attach and update the observer

#pragma once
#include "Observer.h"
#include <list>
using namespace std;

class Observer;

class Subject {
public:
	Subject();
	~Subject();
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
private:
	list<Observer*> *_observers;
};