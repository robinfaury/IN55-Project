#ifndef _PARTICLESYSTEM_H
#define _PARTICLESYSTEM_H

#include "Componant.h"

class ParticleSystem : public Componant
{
private:

public:
	ParticleSystem();
	
	virtual void apply();

	~ParticleSystem();
};

#endif 