#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm.hpp>
#include <gtc/quaternion.hpp>
#include <gtc/matrix_transform.hpp>

#include "Object3D.h"
#include "IObserverMouseMove.h"

class Camera : public Object3D
{
private:
	glm::vec3 up;
	glm::mat4 view;
	glm::mat4 projection;

	glm::vec3 orientation;
	float phi;
	float theta;
	
	Camera();

public:
	Camera(std::string name);

	void update();
	void move(float a);
	void straf(float a);
	void climb(float a);
	void oriente(float dx, float dy);

	void translate(float x, float y, float z);

	glm::mat4 getView() {return this->view;}
	glm::mat4 getProjection() {return this->projection;}

	glm::vec3 getUpVector() {return this->up;}
	glm::vec3 getFocus() {return this->getPostion()+this->orientation;}
	
	~Camera();
};

#endif