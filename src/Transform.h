#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include <glm.hpp>

class Transform
{
protected: 
    glm::vec3* position;
    glm::mat3* rotation;
    glm::vec3* scaling;

public:
	Transform();

	void translate(float x, float y, float z);
	void translate(glm::vec3 translation) {*this->position += translation;}
	void scale(float x, float y, float z);
	void rotate(float alpha, glm::vec3 axis, bool radian = 1);

	glm::vec3 getPosition() {return *this->position;}
	glm::mat3 getRotation() {return *this->rotation;}
	glm::vec3 getScaling() {return *this->scaling;}
	glm::vec3* trackPosition() {return this->position;}
	glm::mat3* trackRotation() {return this->rotation;}
	glm::vec3* trackScaling() {return this->scaling;}
	void setPosition(glm::vec3 newPosition) {this->position->x = newPosition.x;this->position->y = newPosition.y;this->position->z = newPosition.z;}
	void setPosition(glm::vec3* newPosition) {this->position = newPosition;}
	void setRotation(float alpha, glm::vec3 axis, bool radian = 1);
	void setScaling(glm::vec3 newScaling) {this->scaling->x = newScaling.x;this->scaling->y = newScaling.y;this->scaling->z = newScaling.z;}

	~Transform();
};

#endif