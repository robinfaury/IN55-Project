#include "GlobalInformation.h"

GlobalInformation::GlobalInformation()
{

}

void GlobalInformation::setCameraProperty(glm::vec3 cameraPosition, glm::vec3 cameraFocus, glm::vec3 cameraUpVector)
{
	this->cameraPosition = cameraPosition;
	this->cameraFocus = cameraFocus;
	this->cameraUpVector =cameraUpVector;
}

void GlobalInformation::computeModelViewProjectionMatrix()
{
	this->projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	this->view       = glm::lookAt(
								this->cameraPosition,
								this->cameraFocus = cameraFocus,
								this->cameraUpVector
							);
	this->model      = glm::mat4(1.0f);
	this->modelView = this->view * this->model;
	this->MVP = this->projection * this->view * this->model;
}

GlobalInformation::~GlobalInformation()
{

}