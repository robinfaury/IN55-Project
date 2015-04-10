#include "Particle.h"

Particle::Particle(Material* material, float x, float y, float z, bool isDynamic) : PhysicalObject(material, x, y, z, isDynamic)
{
	this->life = rand()%20 + 30;
	this->velocity = glm::vec3(static_cast <float> (rand()) / static_cast <float> (RAND_MAX), 5.0, static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
	this->velocity /= 10;
}

Particle::Particle(Material* material, Geometry* geometry, float x, float y, float z, bool isDynamic) : PhysicalObject(material, geometry, x, y, z, isDynamic)
{
	this->life = rand()%20 + 30;
	this->velocity = glm::vec3(static_cast <float> (rand()) / static_cast <float> (RAND_MAX)-0.5, 2.2, static_cast <float> (rand()) / static_cast <float> (RAND_MAX)-0.5);
	this->velocity /= 10;
}

void Particle::move()
{
	if (this->getPosition().y <= 0.1f)
		return;
	this->velocity -= glm::vec3(0.0f, 9.81f*0.001f, 0.0f);
	translate(this->velocity.x, this->velocity.y, this->velocity.z);
}

Particle::~Particle()
{

}