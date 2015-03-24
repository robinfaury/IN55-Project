#ifndef WORLD_H_
#define WORLD_H_

#include <SFML/Graphics.hpp>

#include "Shader.h"
#include "Mesh.h"
#include "Lamp.h"

class World
{
private:
	std::vector<Shader*> listOfShader;
	std::vector<Mesh*> listOfMesh;
	std::vector<sf::Texture*> listOfTexture;
	std::vector<Lamp*> listOfLamp;

public:
	World();

	void createScene();
	std::vector<Shader*>* GetListOfShader() {return &this->listOfShader;}
	std::vector<Mesh*>* GetListOfMesh() {return &this->listOfMesh;}
	std::vector<Lamp*>* GetListOfLamp() {return &this->listOfLamp;}

	~World();
};

#endif