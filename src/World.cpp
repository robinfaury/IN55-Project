#include "World.h"

World::World()
{
}

void World::createScene()
{
	this->listOfShader.push_back(new Shader("../IN55-Project/res/shaders/basic.vert", "../IN55-Project/res/shaders/basic.frag"));
	this->listOfShader.push_back(new Shader("../IN55-Project/res/shaders/picking.vert", "../IN55-Project/res/shaders/picking.frag"));
	this->listOfShader.push_back(new Shader("../IN55-Project/res/shaders/particle.vert", "../IN55-Project/res/shaders/particle.frag"));

	this->listOfTexture.push_back(new sf::Texture());
	this->listOfTexture[this->listOfTexture.size()-1]->loadFromFile("../IN55-Project/res/images/grass.jpg");
	this->listOfTexture[this->listOfTexture.size()-1]->setSmooth(true);
	this->listOfTexture.push_back(new sf::Texture());
	this->listOfTexture[this->listOfTexture.size()-1]->loadFromFile("../IN55-Project/res/images/rock.jpg");
	this->listOfTexture[this->listOfTexture.size()-1]->setSmooth(true);
	
	this->listOfObjects3D.push_back(new Plan());
	this->listOfObjects3D[this->listOfObjects3D.size()-1]->scale(glm::vec3(4.0, 4.0, 4.0));
	this->listOfObjects3D[this->listOfObjects3D.size()-1]->translate(glm::vec3(0.0, -0.001, 0.0));
	this->listOfObjects3D[this->listOfObjects3D.size()-1]->setTexture(this->listOfTexture[0]);

	this->listOfObjects3D.push_back(new Mesh("../IN55-Project/res/meshs/dragonSD.obj", GL_TRIANGLES));
	this->listOfObjects3D[this->listOfObjects3D.size()-1]->setTexture(this->listOfTexture[1]);
	this->listOfObjects3D[this->listOfObjects3D.size()-1]->scale(glm::vec3(0.2, 0.2, 0.2));
	this->listOfObjects3D[this->listOfObjects3D.size()-1]->translate(glm::vec3(0.0, 1.3, 0.0));
	
	this->listOfObjects3D.push_back(new Sphere(20, 20));
	this->listOfObjects3D[this->listOfObjects3D.size()-1]->scale(glm::vec3(0.5, 0.5, 0.5));
	this->listOfObjects3D[this->listOfObjects3D.size()-1]->setColor(glm::vec3(0.5, 0.0, 0.3));
	this->listOfObjects3D[this->listOfObjects3D.size()-1]->translate(glm::vec3(0.0, 0.5, 0.0));
	
	this->listOfParticleSystem.push_back(new ParticleSystem(glm::vec3(0.0, 0.0, 0.0)));
	this->listOfParticleSystem[0]->generate(100);

	this->listOfLamp.push_back(new Lamp(3.0, 3.4, 5.0));
}

World::~World()
{
	for (int i=0; i<this->listOfShader.size(); ++i)
		delete this->listOfShader[i];
	for (int i=0; i<this->listOfTexture.size(); ++i)
		delete this->listOfTexture[i];
	for (int i=0; i<this->listOfObjects3D.size(); ++i)
		delete this->listOfObjects3D[i];
	for (int i=0; i<this->listOfLamp.size(); ++i)
		delete this->listOfLamp[i];
	for (int i=0; i<this->listOfParticleSystem.size(); ++i)
		delete this->listOfParticleSystem[i];
}