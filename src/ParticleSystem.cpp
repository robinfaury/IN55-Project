#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(Object3D* emitter)
{
	this->emitter = emitter;
}

ParticleSystem::ParticleSystem(glm::vec3 position)
{
	this->position = position;
	this->emitter = NULL;
}

void ParticleSystem::generate(int nbParticles)
{
	this->listOfParticles.clear();
	while(nbParticles--)
		this->listOfParticles.push_back(Particle());
}

void ParticleSystem::draw(GLuint shaderID)
{
	for (int i=0; i<this->listOfParticles.size(); ++i)
		this->listOfParticles[i].draw(shaderID);
}

ParticleSystem::~ParticleSystem()
{

}