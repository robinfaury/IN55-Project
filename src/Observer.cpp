#include "Observer.h"

Observer::Observer()
{

}

void Observer::update(const Observable * obs) const
{
	std::cout << obs->status() << std::endl;
}

void Observer::addObservable(Observable* obs)
{
	m_observables.push_back(obs);
	obs->addObs(this);
}

void Observer::removeObservable(Observable* obs)
{
	m_observables.remove(obs);
}

Observer::~Observer()
{
	std::list<Observable*>::iterator it;
	for (it = m_observables.begin(); it != m_observables.end(); ++it)
	{
		(*it)->delObs(this);
	}
}