#ifndef _OBJECT3D_H
#define _OBJECT3D_H

#include "Transform.h"

class Object3D
{
protected: 
    Transform transform;

public:
	Object3D();
	Object3D(float x, float y, float z);

	glm::vec3 getPosition() {return this->transform.getPosition();}

	~Object3D();
};

#endif