#ifndef MESH_H_
#define MESH_H_

#include "Object3D.h"

class Mesh : public Object3D
{
private:
	bool loaded;

public:
	Mesh();
	Mesh(const char* filename);
	
	bool isLoaded() {return this->loaded;}
	void loadOBJ(const char* filename);

	~Mesh();
};

#endif