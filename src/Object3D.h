#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include <vector>

#include "Object.h"
#include "Transform.h"
#include "Dynamic.h"
#include "Static.h"

class Object3D : public Object
{
protected:
	Transform transform;
	std::vector<Componant*> componants;

	Object3D();
public:
	Object3D(std::string name);

	virtual void translate(float x, float y, float z);
	virtual void translate(glm::vec3 translation);
	virtual void rotate(float alpha, float x, float y, float z);
	virtual void scale(float x, float y, float z);
	virtual void setPosition(float x, float y, float z);
	virtual void setPosition(glm::vec3 position);
	virtual void setRotation(float alpha, float x, float y, float z);
	virtual void setScaling(float x, float y, float z);

	virtual glm::vec3* trackPosition();

	Static* addPhysicComponantStatic();
	virtual Dynamic* addPhysicComponantDynamic();

	virtual void update();

	glm::vec3 getPostion();
	
	~Object3D();
	
};

#endif