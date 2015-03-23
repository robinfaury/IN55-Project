#include "Lamp.h"

Lamp::Lamp()
{

}

Lamp::Lamp(float x, float y, float z)
{
	this->setPosition(x, y, z);
	this->setColor(1.0, 1.0, 1.0);
	this->ambiant = 1.0;
	this->diffuse = 1.0;
	this->specular = 1.0;
}

Lamp::Lamp(float x, float y, float z, float r, float g, float b)
{
	this->setPosition(x, y, z);
	this->setColor(r, g, b);
	this->ambiant = 1.0;
	this->diffuse = 1.0;
	this->specular = 1.0;
}

Lamp::Lamp(float x, float y, float z, float r, float g, float b, float ambiant, float diffuse, float specular)
{
	this->setPosition(x, y, z);
	this->setColor(r, g, b);
	this->ambiant = ambiant;
	this->diffuse = diffuse;
	this->specular = specular;
}

void Lamp::setPosition(float x, float y, float z)
{
	this->position = glm::vec3(x, y, z);
}

void Lamp::setColor(float r, float g, float b)
{
	this->color = glm::vec3(r, g, b);
}

void Lamp::setAmbiant(float a)
{
	this->ambiant = a;
}
void Lamp::setDiffuse(float d)
{
	this->diffuse = d;
}

void Lamp::setSpecular(float s)
{
	this->specular = s;
}

glm::vec3* Lamp::getPosition()
{
	return &this->position;
}

glm::vec3* Lamp::getColor()
{
	return &this->color;
}

float Lamp::getAmbiant()
{
	return this->ambiant;
}

float Lamp::getDiffuse()
{
	return this->diffuse;
}

float Lamp::getSpecular()
{
	return this->specular;
}
	
Lamp::~Lamp()
{

}