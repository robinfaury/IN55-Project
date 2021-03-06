#ifndef _PARTICLESYSTEM_H
#define _PARTICLESYSTEM_H

#include "GraphicComponant.h"
#include "Particle.h"
#include "Material.h"
#include "MultiplePointsGeometry.h"

class ParticleSystem : public GraphicComponant
{
private:
	int nbParticulePerFrame;
	int nbParticuleMax;
	bool continuous;
	int time;
	int globalLife;
	std::vector<Particle*> particles;
	std::vector<glm::vec3> particlesPosition;
	Material* particleMaterial;
	Geometry* particleGeometry;
	Object3D* emitter;
	Geometry* emitterGeometry;
	Drawable drawable;

	void lunchParticle(int n);

public:
	ParticleSystem(int nbParticuleMax, Material* particleMaterial, Geometry* emitterGeometry, bool continuous = true);
	
	void generate(Object3D* emitter, int life);

	virtual void apply(float time, glm::vec3* position, glm::mat3* rotation, glm::vec3* scale, GlobalInformation* globalInformation);

	void setParticuleGeometry(Geometry* geometry) {this->particleGeometry = geometry;}

	~ParticleSystem();
};

#endif 