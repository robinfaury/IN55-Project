#ifndef _CAMERA_H
#define _CAMERA_H

#include "Object3D.h"


class Camera: public Object3D
{
private:

public:
	Camera();
	Camera(float x, float y, float z);

	~Camera();
};

#endif