#include "Lamp.h"

Lamp::Lamp()
{

}

void Lamp::SetPosition(float x, float y, float z)
{
	this->position = glm::vec3(x, y, z);
}

void Lamp::SetColor(float r, float g, float b)
{
	this->color = glm::vec3(r, g, b);
}

void Lamp::SetAmbiant(float a)
{
	this->ambiant = a;
}
void Lamp::SetDiffuse(float d)
{
	this->difuse = d;
}

void Lamp::SetSpecular(float s)
{
	this->specular = s;
}
	
Lamp::~Lamp()
{

}