#ifndef _STATIC_H
#define _STATIC_H

#include "Physic.h"

class Static: public Physic
{
private:

public:
	Static();

	virtual void apply(float time, glm::vec3* position, glm::mat3* rotation, glm::vec3* scale);

	~Static();
};

#endif