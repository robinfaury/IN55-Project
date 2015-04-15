#ifndef _MESH_H
#define _MESH_H

#include "MultiplePointsGeometry.h"

class Mesh: public MultiplePointsGeometry
{
private:
	Mesh();
public:
	Mesh(std::string name);

	~Mesh();
};

#endif