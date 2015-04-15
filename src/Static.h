#ifndef _STATIC_H
#define _STATIC_H

#include "Physic.h"

class Static: public Physic
{
private:

public:
	Static();

	virtual void apply();

	~Static();
};

#endif