#include "Particle.h"

Particle::Particle()
{

}

Particle::Particle(std::string name) : Object3D(name)
{

}

void Particle::update()
{
	--this->life;
	if (this->life > 0)
		Object3D::update();
	else
		setPosition(0.0f, 0.0f, 0.0f);
}

Particle::~Particle()
{

}
