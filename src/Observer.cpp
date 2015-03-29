#include "Observer.h"

Observer::Observer()
{

}

void Observer::update(Observable * obs)
{
	std::cout << obs->Statut() << std::endl;
}

void Observer::addObservable(Observable* obs)
{

}

void Observer::removeObservable(Observable* obs)
{

}

Observer::~Observer()
{

}