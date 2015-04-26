#ifndef _PARTICLESYSTEM_H
#define _PARTICLESYSTEM_H

#include "GraphicComponant.h"

class ParticleSystem : public GraphicComponant
{
private:

public:
	ParticleSystem(int nbParticle, bool continuous = true);
	
	virtual void apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale);

	~ParticleSystem();
};

#endif 