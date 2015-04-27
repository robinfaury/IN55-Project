#include "Dynamic.h"

Dynamic::Dynamic() : Physic()
{

}

void Dynamic::apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale)
{
	this->velocity += glm::vec3(0.0f, -0.001f, 0.0f);
	*this->position += this->velocity;
}

void Dynamic::setVelocity(float x, float y, float z, float celerity)
{
	this->velocity = glm::normalize(glm::vec3(x, y, z))*celerity;
}

Dynamic::~Dynamic()
{

}
