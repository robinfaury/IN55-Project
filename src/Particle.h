#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Object3D.h"

class Particle
{
private:
	int life;
	glm::vec3 position;
	glm::vec3 velocity;
	Object3D* shape;

public:
	Particle();

	void draw(GLuint shaderID);

	glm::vec3* getPosition() {return &this->position;}
	glm::vec3* getVelocity() {return &this->velocity;}

	~Particle();
};

#endif