#include "Particle.h"

Particle::Particle()
{

}

Particle::Particle(std::string name) : Object3D(name)
{

}

void Particle::update()
{
	
}

int Particle::live()
{
	if (this->life < 0)
		return 0;
	--this->life;
	if (this->life > 0)
	{
		Object3D::update(0);
		return 0;
	}
	else
	{
		setPosition(0.0f, 0.0f, 0.0f);
		return -1;
	}
}

Particle::~Particle()
{

}
