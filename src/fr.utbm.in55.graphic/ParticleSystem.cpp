#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
	this->globalEmition = false;
	this->globalLife = 100;
	this->continuousSimulation = false;
	this->particleSize = 1.0f;
}

void ParticleSystem::init(int nbParticles)
{
	glm::vec3 posEmitter = this->emitter->getPosition();
	for (int i=0; i<nbParticles; ++i)
	{
		this->particles.push_back(new Particle(this->particleMaterial, this->particleGeometry, posEmitter.x, posEmitter.y, posEmitter.z, false));
	}
	resizeParticle();
}

void ParticleSystem::resizeParticle()
{
	for (std::vector<Particle*>::iterator particle = this->particles.begin(); particle != this->particles.end(); ++particle)
		(*particle)->rescale(this->particleSize, this->particleSize, this->particleSize);
}

void ParticleSystem::update()
{
	glm::vec3 posEmitter = this->emitter->getPosition();
	for (int i=0; i<5; ++i)
		this->particles.push_back(new Particle(this->particleMaterial, this->particleGeometry, posEmitter.x, posEmitter.y, posEmitter.z, false));
	resizeParticle();

	for (std::vector<Particle*>::iterator particle = this->particles.begin(); particle != this->particles.end(); )
	{
		(*particle)->decreaseLife();
		if ((*particle)->dead())
		{
			particle = this->particles.erase(particle);
			continue;
		}
		(*particle)->move();
		++particle;
	}
}

void ParticleSystem::draw()
{
	if (this->emitter->isVisible())
		this->emitter->draw();
	for (std::vector<Particle*>::iterator particle = this->particles.begin(); particle != this->particles.end(); ++particle)
		if ((*particle)->isVisible())
			(*particle)->draw();
}

std::vector<Particle*>* ParticleSystem::getParticles()
{
	return &this->particles;
}

ParticleSystem::~ParticleSystem()
{
	for (int i=0; i<this->particles.size(); ++i)
		delete this->particles[i];
}

