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

	void translate(float x, float y, float z);
	void rotate(float alpha, float x, float y, float z);
	void scale(float x, float y, float z);
	void setPosition(float x, float y, float z);
	void setRotation(float alpha, float x, float y, float z);
	void setScaling(float x, float y, float z);

	glm::vec3 getPostion();
	
	~Object3D();
	
};

#endif