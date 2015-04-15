#ifndef _COMPONANT_H
#define _COMPONANT_H

#include <string>

#include "Object.h"
#include "Geometry.h"
#include "GlobalInformation.h"

class Componant
{
private:

protected: 
	GlobalInformation* globalInformation;

	Componant();

public:
	virtual void apply() = 0;
	
	~Componant();
};

#endif