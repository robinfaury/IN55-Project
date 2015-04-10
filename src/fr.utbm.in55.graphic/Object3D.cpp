#include "Object3D.h"

Object3D::Object3D()
{
	this->transform.setPosition(glm::vec3(0.0, 0.0, 0.0));
}

Object3D::Object3D(float x, float y, float z)
{
	this->transform.setPosition(glm::vec3(x, y, z));
}

Object3D::~Object3D()
{

}
