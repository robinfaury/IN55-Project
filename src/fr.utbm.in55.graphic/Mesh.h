#ifndef _MESH_H
#define _MESH_H

#include "Geometry.h"

class Mesh: public Geometry
{
private:
	bool loaded;
	Mesh() {}

public:
	
	Mesh(const char* filename, int drawingMode);
	
	bool isLoaded() {return this->loaded;}
	void loadOBJ(const char* filename);

	~Mesh();
};

#endif