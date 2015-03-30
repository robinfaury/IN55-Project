#ifndef OBJECTPROPERTIES_H_
#define OBJECTPROPERTIES_H_

#include <iostream>

#include "IObserver.h"

class ObjectProperties : public IObserver
{
public:
	ObjectProperties();

	void update(std::string data);

	~ObjectProperties();
};

#endif