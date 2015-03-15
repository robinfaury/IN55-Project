#ifndef WORLD_H_
#define WORLD_H_

#include "Mesh.h"

class World
{
private:

	std::vector<Shader*> listOfShader;
	std::vector<Mesh*> listOfMesh;

public:
	World();

	void createScene();
	std::vector<Mesh*> GetListOfMesh() {return this->listOfMesh;}

	~World();
};

#endif