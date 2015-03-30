#pragma once

#include <list>
#include "Observer.h"

using namespace std;

typedef int Info;

class Observer;

class Observable
{
private:
	std::list<Observer*> m_list;

	typedef std::list<Observer*>::iterator iterator;
	typedef std::list<Observer*>::const_iterator const_iterator;

public:
	void addObs(Observer* obs);
	void delObs(Observer* obs);

	virtual Info status(void) const = 0;
	virtual ~Observable();
protected:
	void notify(void);

};