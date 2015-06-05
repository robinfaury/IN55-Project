#include "Transform.h"

Transform::Transform()
{
	this->position = new glm::vec3(0.0f, 0.0f, 0.0f);
	this->scaling = new glm::vec3(1.0f, 1.0f, 1.0f);
	this->rotation = new glm::mat3();
}

void Transform::translate(float x, float y, float z)
{
	this->position->x += x;
	this->position->y += y;
	this->position->z += z;
}

void Transform::scale(float x, float y, float z)
{
	this->scaling->x *= x;
	this->scaling->y *= y;
	this->scaling->z *= z;
}

void Transform::rotate(float alpha, glm::vec3 axis, bool radian)
{
	glm::normalize(axis);
	if (!radian)
		alpha = 3.14159265359f * alpha / 180.0f;
	glm::normalize(axis);
	float c = cos(alpha), s = sin(alpha);
	(*this->rotation)[0][0] = axis.x*axis.x + (1 - axis.x*axis.x)*c;		(*this->rotation)[1][0] = axis.x*axis.y*(1-c) - axis.z*s;				(*this->rotation)[2][0] = axis.x*axis.z*(1-c) + axis.y*s;
	(*this->rotation)[0][1] = axis.x*axis.y*(1-c) + axis.z*s;				(*this->rotation)[1][1] = axis.y*axis.y + (1 - axis.y*axis.y)*c;		(*this->rotation)[2][1] = axis.y*axis.z*(1-c) - axis.x*s;
	(*this->rotation)[0][2] = axis.x*axis.z*(1-c) - axis.y*s;				(*this->rotation)[1][2] = axis.y*axis.z*(1-c) + axis.x*s;				(*this->rotation)[2][2] = axis.z*axis.z + (1 - axis.z*axis.z)*c;
}

void Transform::setRotation(float alpha, glm::vec3 axis, bool radian)
{
	rotate(alpha, axis, radian);
}

Transform::~Transform()
{

}