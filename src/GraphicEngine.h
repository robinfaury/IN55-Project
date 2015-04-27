#ifndef _GRAPHICENGINE_H
#define _GRAPHICENGINE_H

#include <map>

#include "Mesh.h"
#include "Sphere.h"
#include "Cube.h"
#include "Plan.h"
#include "Point.h"
#include "Particle.h"
#include "GraphicObject3D.h"
#include "OBJLoader.h"

class GraphicEngine
{
private:
	std::map<std::string, Shader*> shaders;
	std::map<std::string, Texture*> textures;
	std::map<std::string, Material*> materials;
	std::map<std::string, Geometry*> geometry;
	std::map<std::string, GraphicObject3D*> objects3D;
	std::map<std::string, Camera*> cameras;

	OBJLoader objLoader;
	GlobalInformation globalInformation;

	void loadShader();
	void loadTexture();
	void loadGeometry();
	void loadObject3D();
	void loadMaterials();
	void loadCamera();
	
public:
	GraphicEngine(int heightWindow, int widthWindow);

	void loadLevel();
	void draw();

	GlobalInformation* getGlobalInformation() {return &this->globalInformation;}
	Camera* getCurrentCamera() {return this->globalInformation.getCurrentCamera();}

	~GraphicEngine();
};

#endif