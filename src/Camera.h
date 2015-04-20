#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm.hpp>
#include <gtc/quaternion.hpp>
#include <gtc/matrix_transform.hpp>
#include <string>

#include "Object3D.h"
#include "IObserverMouseMove.h"

class Camera : public Object3D, public IObserverMouseMove
{
private:
	glm::vec3 focus;
	glm::vec3 up;
	glm::mat4 view;
	glm::mat4 projection;
	
	Camera();

public:
	Camera(std::string name);

	void update(float dx, float dy);

	glm::mat4 getView() {return this->view;}
	glm::mat4 getProjection() {return this->projection;}
	
	~Camera();
};

#endif