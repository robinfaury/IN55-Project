#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(int nbParticle, Material* particleMaterial, bool continuous) : GraphicComponant()
{
	this->continuous = continuous;
	this->particleMaterial = particleMaterial;
	this->particleGeometry = NULL;
	this->particles.reserve(nbParticle);
	this->nbParticle = nbParticle;
}

void ParticleSystem::generate(Object3D* emitter, int life)
{
	this->time = 0;
	this->globalLife = life;
	this->emitter = emitter;
	for(int i = 0; i < this->nbParticle; ++i)
	{
		Particle* p = new Particle(std::to_string(nbParticle));

		Dynamic* dynamicSystem = p->addPhysicComponantDynamic();
		dynamicSystem->setPosition(p->trackPosition());
		
		this->particlesPosition.push_back(p->getPostion());
		this->particles.push_back(p);
	}
	this->drawable.loadOnGraphicCard(GL_POINTS, &this->particlesPosition);
}

void ParticleSystem::lunchParticle(int n)
{
	for (int i=0; i<n; ++i)
	{
		this->particles[this->time%this->globalLife*i+i]->setPosition(this->emitter->getPostion());
		this->particles[this->time%this->globalLife*i+i]->setLife(this->globalLife);
		Dynamic* ds = this->particles[this->time%this->globalLife*i+i]->getDynamicSystem();
		ds->setVelocity((rand()%100/100.0f-0.5f)/abs(cos(this->time/300.0f)*3), 1.0f, (rand()%100/100.0f-0.5f)/abs(cos(this->time/300.0f)*3), (rand()%100/100.0f)*0.01f + 0.049f);
	}
}

void ParticleSystem::apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale, GlobalInformation* globalInformation)
{
	++this->time;
	lunchParticle(this->nbParticle/this->globalLife);
	for (std::vector<Particle*>::iterator currentParticle = this->particles.begin(); currentParticle != this->particles.end(); ++currentParticle)
	{
		(*currentParticle)->update();
	}
	for (int i=0; i<this->particlesPosition.size(); ++i)
		this->particlesPosition[i] = this->particles[i]->getPostion();
	this->drawable.updateStream(&this->particlesPosition);

	glm::mat4 rotationTranslation = glm::mat4(rotation);

	GLuint programID = this->particleMaterial->getShader()->getProgramID();
	glUseProgram(programID);
		glUniformMatrix4fv(glGetUniformLocation(programID, "Model"), 1, GL_FALSE, &rotationTranslation[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "View"), 1, GL_FALSE, &globalInformation->getCurrentCamera()->getView()[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "Projection"), 1, GL_FALSE, &globalInformation->getCurrentCamera()->getProjection()[0][0]);
		
		glUniform3f(glGetUniformLocation(programID, "ObjectScale"), scale.x, scale.y, scale.z);
		
		glm::vec3 posCam = globalInformation->getCurrentCamera()->getPostion();
		glUniform3f(glGetUniformLocation(programID, "PosCamera"), posCam.x, posCam.y, posCam.z);
		glUniform3f(glGetUniformLocation(programID, "PosLamp01"), 4.0f, 2.0f, 4.0f);
		
		if (this->particleMaterial->getTexture() != NULL)
			glBindTexture(GL_TEXTURE_2D, this->particleMaterial->getTexture()->getTextureID());
		glUniform1i(glGetUniformLocation(programID, "isTexture"), (this->particleMaterial->getTexture() == NULL)? 0 : 1);
		glm::vec3 color = this->particleMaterial->getColor();
		glUniform3f(glGetUniformLocation(programID, "ObjectColor"), color.x, color.y, color.z);

		this->drawable.draw();

		glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}

ParticleSystem::~ParticleSystem()
{

}
