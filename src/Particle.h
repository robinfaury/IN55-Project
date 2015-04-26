#ifndef _PARTICLE_H
#define _PARTICLE_H

#include "GraphicObject3D.h"

class Particle: public GraphicObject3D
{
private:

	Particle();

public:
	Particle(GlobalInformation* globalInformation, std::string name);

	~Particle();
};

#endif