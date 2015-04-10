#ifndef _GRAPHICENGINE_H
#define _GRAPHICENGINE_H

#include <vector>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "SceneGraph.h"
#include "Camera.h"
#include "Lamp.h"
#include "PhysicalObject.h"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"
#include "Geometry.h"
#include "ParticleSystem.h"

class GraphicEngine
{
private: 
	std::vector<Shader*> shaders;
	std::vector<Texture*> textures;
	std::vector<Material*> materials;
	std::vector<Geometry*> geometrys;
	std::vector<PhysicalObject*> staticObjects;
	std::vector<PhysicalObject*> dynamicObjects;
	std::vector<ParticleSystem*> particleSystems;
	std::vector<Lamp*> lamps;
	std::vector<Camera*> cameras;

	Camera* currentCamera;
	SceneGraph sceneGraph;

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	void createWorld();
	void EnableShader(GLuint programID);
	void DisableShader();

public: 
	GraphicEngine();

	void init();

	void update( float cursorDx,  float cursorDy, std::chrono::system_clock::time_point time);

	SceneGraph* getSceneGraph();
	std::vector<PhysicalObject*>* getStaticObject() {return &this->staticObjects;}
	std::vector<PhysicalObject*>* getDynamicObject() {return &this->dynamicObjects;}

	~GraphicEngine();
};

#endif