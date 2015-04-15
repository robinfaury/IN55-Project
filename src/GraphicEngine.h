#ifndef _GRAPHICENGINE_H
#define _GRAPHICENGINE_H

#include <map>

#include "Mesh.h"
#include "Sphere.h"
#include "Cube.h"
#include "Plan.h"
#include "Point.h"
#include "Object3D.h"
#include "OBJLoader.h"
#include "GlobalInformation.h"

class GraphicEngine
{
private:
	std::map<std::string, Shader*> shaders;
	std::map<std::string, Texture*> textures;
	std::map<std::string, Material*> materials;
	std::map<std::string, Geometry*> geometry;
	std::map<std::string, Object3D*> objects3D;

	OBJLoader objLoader;
	GlobalInformation globalInformation;

	void loadShader();
	void loadTexture();
	void loadGeometry();
	void loadObject3D();
	void loadMaterials();
	
public:
	GraphicEngine();

	void loadLevel();
	void draw();

	~GraphicEngine();
};

#endif