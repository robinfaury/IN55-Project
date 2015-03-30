#include "Observable.h"


Observable::Observable()
{
}


Observable::~Observable()
{
}

void Observable::notify(string data) const
{
	// Notifier tous les observers
	set<IObserver*>::const_iterator it;
	for (it = list_observers.begin(); it != list_observers.end(); ++it)
	{
		(*it)->update(data);
	}
}

void Observable::addObserver(IObserver* observer)
{
	// Ajouter un observer a la liste
	list_observers.insert(observer);
}

void Observable::removeObserver(IObserver* observer)
{
	// Enlever un observer a la liste
	list_observers.erase(observer);
}