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

void Object3D::translate(glm::vec3 translation)
{
	this->transform.translate(translation);
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

void Object3D::setPosition(glm::vec3 position)
{
	this->transform.setPosition(position);
}

void Object3D::setPosition(glm::vec3* position)
{
	this->transform.setPosition(position);
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

glm::vec3 Object3D::getScale()
{
	return this->transform.getScaling();
}

glm::vec3* Object3D::trackPosition()
{
	return this->transform.trackPosition();
}

Static* Object3D::addPhysicComponantStatic()
{
	Static* s = new Static();
	this->componants.push_back(s);
	return s;
}

Dynamic* Object3D::addPhysicComponantDynamic(float masse, float gravityInfluance)
{
	Dynamic* d = new Dynamic(masse, gravityInfluance);
	this->componants.push_back(d);
	return d;
}

void Object3D::update(float time)
{
	for (std::vector<Componant*>::iterator currentComponent = this->componants.begin(); currentComponent != this->componants.end(); ++currentComponent)
		(*currentComponent)->apply(time, this->transform.trackPosition(), this->transform.trackRotation(), this->transform.trackScaling());
}

Object3D::~Object3D()
{
	
}
