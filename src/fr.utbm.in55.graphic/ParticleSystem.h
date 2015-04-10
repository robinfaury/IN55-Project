#ifndef _PARTICLESYSTEM_H
#define _PARTICLESYSTEM_H

#include <vector>

#include "Particle.h"

class ParticleSystem
{
protected: 
	PhysicalObject* emitter;
    std::vector<Particle*> particles;
	Geometry* particleGeometry;
	Material* particleMaterial;
	float particleSize;

	bool globalEmition;
	int globalLife;
	bool continuousSimulation;

	void resizeParticle();

public: 
	ParticleSystem();

	void setEmitter(PhysicalObject* emitter) {this->emitter = emitter;}
	void setParticleGeometry(Geometry* particleGeometry) {this->particleGeometry = particleGeometry;}
	void setParticleMaterial(Material* particleMaterial) {this->particleMaterial = particleMaterial;}
	void setParticleSize(float size) {this->particleSize = size;}
	Material* getParticleMaterial() {return this->particleMaterial;}

	void init(int nbParticles);
	void update();
	void draw();
    
    std::vector<Particle*>* getParticles();

	~ParticleSystem();
};

#endif //_PARTICLESYSTEM_H