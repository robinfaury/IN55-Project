#pragma once

#include <string>
#include <set>
#include "Observer"

using namespace std;

typedef int Info;

class Observable
{
private:
	set<IObserver*> list_observers;

public:
	void notify(string data) const
	{
		// Notifier tous les observers
		for (set<IObserver*>::const_iterator it = list_observers.begin();
			it != list_observers.end(); ++it)
			(*it)->update(data);
	}

	void addObserver(IObserver* observer)
	{
		// Ajouter un observer a la liste
		list_observers.insert(observer);
	}

	void removeObserver(IObserver* observer)
	{
		// Enlever un observer a la liste
		list_observers.erase(observer);
	}
};