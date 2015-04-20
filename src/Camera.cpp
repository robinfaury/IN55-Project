#include "Camera.h"

Camera::Camera()
{
	
}

Camera::Camera(std::string name) : Object3D(name)
{
	this->focus = glm::vec3(0.0f, 0.0f, 0.0f);
	this->up = glm::vec3(0.0f, 1.0f, 0.0f);
	this->projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
}

void Camera::update(float dx, float dy)
{
	this->view = glm::lookAt(this->getPostion(), this->focus, this->up);
}

Camera::~Camera()
{

}