#ifndef _PARTICLESYSTEM_H
#define _PARTICLESYSTEM_H

#include "Componant.h"

class ParticleSystem : public Componant
{
private:

public:
	ParticleSystem();
	
	virtual void apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale);

	~ParticleSystem();
};

#endif 