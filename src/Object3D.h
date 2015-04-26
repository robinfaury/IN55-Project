#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include "Object.h"
#include "Transform.h"

class Object3D : public Object
{
protected:
	Transform transform;

	Object3D();
public:
	Object3D(std::string name);

	virtual void translate(float x, float y, float z);
	virtual void rotate(float alpha, float x, float y, float z);
	virtual void scale(float x, float y, float z);
	virtual void setPosition(float x, float y, float z);
	virtual void setRotation(float alpha, float x, float y, float z);
	virtual void setScaling(float x, float y, float z);

	glm::vec3 getPostion();
	
	~Object3D();
	
};

#endif