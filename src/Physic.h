#ifndef _PHYSIC_H
#define _PHYSIC_H

#include "GraphicComponant.h"


class Physic: public GraphicComponant
{
protected:

public:
	Physic();

	virtual void apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale) = 0;

	~Physic();
};

#endif