#ifndef _PHYSIC_H
#define _PHYSIC_H

#include "Componant.h"


class Physic: public Componant
{
protected:

public:
	Physic();

	virtual void apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale) = 0;

	~Physic();
};

#endif