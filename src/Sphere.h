#ifndef ICOSPHERE_H_
#define ICOSPHERE_H_

#include "Object3D.h"

class Sphere : public Object3D
{
private:
	void generate(int M, int N);

public:
	Sphere();
	Sphere(int M, int N);
	
	~Sphere();
};

#endif