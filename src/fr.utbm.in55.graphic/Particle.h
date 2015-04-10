#ifndef _PARTICLE_H
#define _PARTICLE_H

#include "PhysicalObject.h"

class Particle: public PhysicalObject
{
private: 
    int life;
	glm::vec3 velocity;

	Particle() {}
public:
	Particle(Material* material, float x, float y, float z, bool isDynamic = false);
	Particle(Material* material, Geometry* geometry, float x, float y, float z, bool isDynamic = false);

	void move();

	void decreaseLife() {--this->life;}
	bool dead() {return (this->life < 0)? true : false;}

	~Particle();
};

#endif