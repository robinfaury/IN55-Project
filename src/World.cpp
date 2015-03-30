#include "World.h"

World::World()
{
}

void World::createScene()
{
	this->listOfShader.push_back(new Shader("../IN55-Project/res/shaders/basic.vert", "../IN55-Project/res/shaders/basic.frag"));
	this->listOfShader.push_back(new Shader("../IN55-Project/res/shaders/picking.vert", "../IN55-Project/res/shaders/picking.frag"));

	this->listOfTexture.push_back(new sf::Texture());
	this->listOfTexture[this->listOfTexture.size()-1]->loadFromFile("../IN55-Project/res/images/grass.jpg");

	this->listOfMesh.push_back(new Plan());
	this->listOfMesh[this->listOfMesh.size()-1]->scale(glm::vec3(4.0, 4.0, 4.0));
	this->listOfMesh[this->listOfMesh.size()-1]->translate(glm::vec3(0.0, -0.001, 0.0));
	this->listOfMesh[this->listOfMesh.size()-1]->setTexture(this->listOfTexture[0]);

	this->listOfMesh.push_back(new Mesh("../IN55-Project/res/meshs/Big_Ben.obj", GL_TRIANGLES));
	
	this->listOfMesh.push_back(new Sphere(20, 20));
	this->listOfMesh[this->listOfMesh.size()-1]->scale(glm::vec3(0.5, 0.5, 0.5));
	this->listOfMesh[this->listOfMesh.size()-1]->setColor(glm::vec3(0.5, 0.0, 0.3));
	this->listOfMesh[this->listOfMesh.size()-1]->translate(glm::vec3(0.0, 0.5, 0.0));

	

	this->listOfLamp.push_back(new Lamp(3.0, 3.4, 5.0));
}

World::~World()
{

}