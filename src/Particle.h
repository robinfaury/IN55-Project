#ifndef _PARTICLE_H
#define _PARTICLE_H

#include "Object3D.h"

class Particle: public Object3D
{
private:
	int life;
	int maxLife;

	Dynamic* dynamicSystem;

	Particle();

public:
	Particle(std::string name);

	virtual void update();
	int live();

	virtual Dynamic* addPhysicComponantDynamic(float masse, float gravityInfluance) {return this->dynamicSystem = Object3D::addPhysicComponantDynamic(masse, gravityInfluance);}

	void setLife(int life) {this->life = life; this->maxLife = life;}
	int getLife() {return this->life;}

	Dynamic* getDynamicSystem() {return this->dynamicSystem;}

	~Particle();
};

#endif