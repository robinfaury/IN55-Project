#ifndef WORLD_H_
#define WORLD_H_

#include <SFML/Graphics.hpp>

#include "Shader.h"
#include "Mesh.h"
#include "Plan.h"
#include "Sphere.h"
#include "Lamp.h"
#include "ParticleSystem.h"
#include "PhysicalSystem.h"

class World
{
private:
	std::vector<Shader*> listOfShader;
	std::vector<Object3D*> listOfObjects3D;
	std::vector<sf::Texture*> listOfTexture;
	std::vector<Lamp*> listOfLamp;
	std::vector<ParticleSystem*> listOfParticleSystem;
	PhysicalSystem physique;

public:
	World();

	void createScene();
	std::vector<Shader*>* GetListOfShader() {return &this->listOfShader;}
	std::vector<Object3D*>* GetListOfObjects3D() {return &this->listOfObjects3D;}
	std::vector<Lamp*>* GetListOfLamp() {return &this->listOfLamp;}
	std::vector<ParticleSystem*>* GetListOfParticleSystem() {return &this->listOfParticleSystem;}

	void callPhysicalSystem() {this->physique.compute(&this->listOfParticleSystem);}

	~World();
};

#endif