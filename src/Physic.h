#ifndef _PHYSIC_H
#define _PHYSIC_H

#include "Componant.h"


class Physic: public Componant
{
protected:

public:
	Physic();

	virtual void apply() = 0;

	~Physic();
};

#endif