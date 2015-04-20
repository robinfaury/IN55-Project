#ifndef IOBSERVABLEMOUSEMOVE_H_
#define IOBSERVABLEMOUSEMOVE_H_

#include <set>

#include "IObserverMouseMove.h"

class IObservableMouseMove
{
private:
	std::set<IObserverMouseMove*> list_observers;

public:
	void notify(float dx, float dy) const
	{
		for (std::set<IObserverMouseMove*>::const_iterator it = list_observers.begin(); it != list_observers.end(); ++it)
			(*it)->update(dx, dy);
	}

	void addObserver(IObserverMouseMove* observer)
	{
		list_observers.insert(observer);
	}

	void removeObserver(IObserverMouseMove* observer)
	{
		list_observers.erase(observer);
	}
};

#endif