#ifndef _GLOBALINFORMATION_H
#define _GLOBALINFORMATION_H

#include "Camera.h"

class GlobalInformation
{
private:
	Camera* currentCamera;

public:
	GlobalInformation();

	void setCurrentCamera(Camera* camera) {this->currentCamera = camera;}
	Camera* getCurrentCamera() {return this->currentCamera;}

	~GlobalInformation();

};

#endif