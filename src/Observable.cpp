#include "Observable.h"


Observable::Observable()
{
}


Observable::~Observable()
{
}

void Observable::AddObs(Observer* obs)
{
	m_list.push_back(obs);
}

void Observable::DelObs(Observer* obs)
{
	for (list<Observer*>::iterator it = m_list.begin(); it != m_list.end(); ++it)
	{
		if (obs == *it)
			it = m_list.erase(it);
	}
}