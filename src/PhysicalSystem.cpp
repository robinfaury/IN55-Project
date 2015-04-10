#include "PhysicalSystem.h"

PhysicalSystem::PhysicalSystem()
{
	this->gravity = glm::vec3(0.0, -0.01, 0.0);
}

void PhysicalSystem::compute(std::vector<ParticleSystem*>* listOfParticleSystem)
{
	for (int i=0; i<listOfParticleSystem->size(); ++i)
	{
		for (int j=0; j<(*listOfParticleSystem)[i]->getListOfParticles()->size(); ++j)
		{
			Particle* p = &(*(*listOfParticleSystem)[i]->getListOfParticles())[j];
			glm::vec3* pos = p->getPosition();
			glm::vec3* velocity = p->getVelocity();
			pos[0] += velocity[0] + this->gravity[0];
			pos[1] += velocity[1] + this->gravity[1];
			pos[2] += velocity[2] + this->gravity[2];
			velocity[0] += this->gravity[0];
			velocity[1] += this->gravity[1];
			velocity[2] += this->gravity[2];
		}
	}
}

PhysicalSystem::~PhysicalSystem()
{

}