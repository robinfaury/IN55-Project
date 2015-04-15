#ifndef _OBJLOADER_H
#define _OBJLOADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Mesh.h"

class OBJLoader
{
private:

public:
	OBJLoader();

	void loadOBJ(std::string filename, Mesh* mesh);

	~OBJLoader();
};

#endif