#include "Camera.h"

Camera::Camera()
{
	
}

Camera::Camera(std::string name) : Object3D(name)
{
	this->up = glm::vec3(0.0f, 1.0f, 0.0f);
	this->projection = glm::perspective(45.0f, 16.0f / 9.0f, 0.1f, 100.0f);
	//this->projection = glm::ortho(0.0f, 1600.0f, 900.0f, 0.0f, 0.0f, 1000.0f);
	this->phi = 0.0f;
	this->theta = -90.0f;
	this->orientation = glm::vec3(-1.0f, 0.0f, 0.0f);
}

void Camera::update()
{
	this->view = glm::lookAt(this->getPostion(), this->getPostion()+this->orientation, this->up);
}


void Camera::move(float a)
{
	this->translate(this->orientation.x*a, this->orientation.y*a, this->orientation.z*a);
	update();
}

void Camera::straf(float a)
{
	glm::vec3 crossVector = cross(this->up, this->orientation);
	this->translate(crossVector.x*a, crossVector.y*a, crossVector.z*a);
	update();
}

void Camera::climb(float a)
{
	this->translate(0.0f, 1.0f*a, 0.0f);
}

void Camera::oriente(int dx, int dy)
{
	if (abs(dx) > 800 || abs(dy) > 800 || dx == 0 || dy == 0)
		return;
	this->phi -= static_cast<float>(dy)*0.2f;
	this->theta -= static_cast<float>(dx)*0.2f;

	if (this->phi > 89.0f)
		this->phi = 89.0f;
	else if (this->phi < -89.0f)
		this->phi = -89.0f;

	float phiRad = 3.14159265359f * this->phi / 180.0f;
	float thetaRad = 3.14159265359f * this->theta / 180.0f;

	this->orientation.x = cos(phiRad) * sin(thetaRad);
	this->orientation.y = sin(phiRad);
	this->orientation.z = cos(phiRad) * cos(thetaRad);

	update();
}

void Camera::translate(float x, float y, float z)
{
	Object3D::translate(x, y, z);
	update();
}

Camera::~Camera()
{

}