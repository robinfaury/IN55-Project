#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <iostream>
#include <list>
#include <iterator>

#include "Observable.h"

class Observer
{

protected:
	std::list<Observable*> m_observables;

public:
	Observer();

	virtual void update(const Observable * obs) const;
	void addObservable(Observable* obs);
	void removeObservable(Observable* obs);

	virtual ~Observer() = 0;
};

#endif