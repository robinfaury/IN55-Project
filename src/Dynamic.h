#ifndef _DYNAMIC_H
#define _DYNAMIC_H

#include "Physic.h"

class Dynamic: public Physic
{
private:
	glm::vec3 velocity;

	Dynamic() {}

public:
	Dynamic(float masse, float gravityInfluance);

	virtual void apply(float time, glm::vec3* position, glm::mat3* rotation, glm::vec3* scale);

	void setVelocity(float x, float y, float z, float celerity);

	~Dynamic();
};

#endif 