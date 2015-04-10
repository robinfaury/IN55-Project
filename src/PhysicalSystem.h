#ifndef PHYSICALSYSTEM_H_
#define PHYSICALSYSTEM_H_

#include "ParticleSystem.h"

class PhysicalSystem
{
private:
	glm::vec3 gravity;

public:
	PhysicalSystem();

	void compute(std::vector<ParticleSystem*>* listOfParticleSystem);

	~PhysicalSystem();
};

#endif