#ifndef PARTICLESYSTEM_H_
#define PARTICLESYSTEM_H_

#include "Particle.h"

class ParticleSystem
{
private:
	std::vector<Particle> listOfParticles;
	Object3D* emitter;
	glm::vec3 position;
	ParticleSystem() {}

public:
	ParticleSystem(Object3D* emitter);
	ParticleSystem(glm::vec3 position);

	void generate(int nbParticles);
	void draw(GLuint shaderID);

	std::vector<Particle>* getListOfParticles() {return &this->listOfParticles;}

	~ParticleSystem();
};

#endif