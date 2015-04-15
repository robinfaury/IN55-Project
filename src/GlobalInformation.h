#ifndef _GLOBALINFORMATION_H
#define _GLOBALINFORMATION_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class GlobalInformation
{
private:
	glm::vec3 cameraPosition;
	glm::vec3 cameraFocus;
	glm::vec3 cameraUpVector;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	glm::mat4 modelView;
	glm::mat4 MVP;

public:
	GlobalInformation();

	void setCameraProperty(glm::vec3 cameraPosition, glm::vec3 cameraFocus, glm::vec3 cameraUpVector);
	void computeModelViewProjectionMatrix();

	glm::mat4* getModel() {return &this->model;}
	glm::mat4* getView() {return &this->view;}
	glm::mat4* getProjection() {return &this->projection;}
	glm::mat4* getModelView() {return &this->modelView;}
	glm::mat4* getMVP() {return &this->MVP;}

	glm::vec3* getCameraPosition() {return &this->cameraPosition;}

	~GlobalInformation();

};

#endif