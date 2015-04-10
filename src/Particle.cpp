#include "Particle.h"

Particle::Particle()
{
	this->life = 100;
	this->position = glm::vec3(0.0, 0.0, 0.0);
	this->velocity = glm::vec3(0.0, 0.1, 0.0);
	this->shape = NULL;
}

void Particle::draw(GLuint shaderID)
{
	if (this->shape == NULL)
	{
		glUniform3f(glGetUniformLocation(shaderID, "posParticle"), this->position.x, this->position.y, this->position.z);
		glDrawArrays(GL_POINTS, 0, 1);
	}
}

Particle::~Particle()
{

}