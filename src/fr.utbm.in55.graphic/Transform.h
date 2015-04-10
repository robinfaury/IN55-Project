#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include "glm.hpp"

class Transform
{
protected: 
    glm::vec3 position;
    glm::mat3 rotation;
    glm::vec3 scaling;

public:
	Transform();

	void translate(float x, float y, float z);
	void scale(float x, float y, float z);
	void rescale(float x, float y, float z);
	void rotate(float alpha, glm::vec3 axis, bool radian = 1);

	glm::vec3 getPosition() {return this->position;}
	glm::mat3 getRotation() {return this->rotation;}
	glm::vec3 getScaling() {return this->scaling;}
	void setPosition(glm::vec3 newPosition) {this->position = newPosition;}
	void setRotation(glm::mat3 newRotation) {this->rotation = newRotation;}
	void setScaling(glm::vec3 newScaling) {this->scaling = newScaling;}

	~Transform();
};

#endif