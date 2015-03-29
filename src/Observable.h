#pragma once

#include <list>
#include "Observer"

using namespace std;

typedef int Info;

class Observable
{
private:
	std::list<Observer*> m_list;

	typedef std::list<Observer*>::iterator iterator;
	typedef std::list<Observer*>::const_iterator const_iterator;

public:
	void AddObs(Observer* obs);
	void DelObs(Observer* obs);

	virtual Info Statut(void) const = 0;
	virtual ~Observable();
protected:
	void Notify(void);

};