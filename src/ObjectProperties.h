#ifndef OBJECTPROPERTIES_H_
#define OBJECTPROPERTIES_H_

#include "Observer.h"

class ObjectProperties : public Observer
{

protected:
	std::list<Observable*> m_observables;

public:
	ObjectProperties();

	void update(const Observable * obs) const;

	~ObjectProperties();
};

#endif