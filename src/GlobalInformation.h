#ifndef _GLOBALINFORMATION_H
#define _GLOBALINFORMATION_H

#include "Camera.h"

class GlobalInformation
{
private:
	Camera* currentCamera;
	int height;
	int width;

public:
	GlobalInformation();

	void setSizeWindow(int h, int w);
	void setCurrentCamera(Camera* camera) {this->currentCamera = camera;}
	Camera* getCurrentCamera() {return this->currentCamera;}

	int getHeightWindow() {return this->height;}
	int getWidthWindow() {return this->width;}

	~GlobalInformation();

};

#endif