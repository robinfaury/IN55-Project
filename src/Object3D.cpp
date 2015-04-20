#include "Object3D.h"

Object3D::Object3D()
{
	
}

Object3D::Object3D(std::string name)
{
	
}

void Object3D::translate(float x, float y, float z)
{
	this->transform.translate(x, y, z);
}

void Object3D::rotate(float alpha, float x, float y, float z)
{
	this->transform.rotate(alpha, glm::vec3(x, y, z));
}

void Object3D::scale(float x, float y, float z)
{
	this->transform.scale(x, y, z);
}

void Object3D::setPosition(float x, float y, float z)
{
	this->transform.setPosition(glm::vec3(x, y, z));
}

void Object3D::setRotation(float alpha, float x, float y, float z)
{
	this->transform.setRotation(alpha, glm::vec3(x, y, z), false);
}

void Object3D::setScaling(float x, float y, float z)
{
	this->transform.setScaling(glm::vec3(x, y, z));
}

glm::vec3 Object3D::getPostion()
{
	return this->transform.getPosition();
}

Object3D::~Object3D()
{
	
}
