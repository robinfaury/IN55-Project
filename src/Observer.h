#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <iostream>
#include <list>
#include <iterator>

class Observer
{

protected:
	std::list<Observable*> m_observables;
	std::list<Observable*>::iterator m_obs_it;
	std::list<Observable*>::iterator m_obs_const_it;

public:
	Observer();

	virtual void update(Observable * obs);
	void addObservable(Observable* obs);
	void removeObservable(Observable* obs);

	~Observer();
};

#endif