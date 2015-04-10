#ifndef _LAMP_H
#define _LAMP_H

#include "Object3D.h"


class Lamp: public Object3D
{
private:

public:
	Lamp();
	Lamp(float x, float y, float z);

	~Lamp();
};

#endif