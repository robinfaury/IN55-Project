#ifndef _PHYSIC_H
#define _PHYSIC_H

#include "Componant.h"


class Physic: public Componant
{
protected:
	glm::vec3* position;
	float masse;
	float gravityInfluance;

	Physic() {}

public:
	Physic(float masse, float gravityInfluance);

	virtual void apply(glm::vec3* position, glm::mat3* rotation, glm::vec3* scale) {}

	void setPosition(glm::vec3* position) {this->position = position;}

	~Physic();
};

#endif