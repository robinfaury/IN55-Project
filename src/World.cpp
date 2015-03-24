#include "World.h"

World::World()
{
}

void World::createScene()
{
	this->listOfShader.push_back(new Shader("../IN55-Project/res/shader/basic.vert", "../IN55-Project/res/shader/basic.frag"));

	this->listOfMesh.push_back(new Mesh("../IN55-Project/res/cube_n.obj"));
	this->listOfMesh[this->listOfMesh.size()-1]->translate(glm::vec3(0.0, 1.0, 0.0));
	this->listOfMesh[this->listOfMesh.size()-1]->rotate(45, glm::vec3(0.0, 1.0, 0.0), 0);
	this->listOfMesh[this->listOfMesh.size()-1]->setColor(glm::vec3(1.0, 0.0, 0.3));
	this->listOfMesh.push_back(new Mesh("../IN55-Project/res/sphere_n.obj"));
	this->listOfMesh[this->listOfMesh.size()-1]->scale(glm::vec3(0.5, 1.0, 0.5));
	this->listOfMesh.push_back(new Mesh("../IN55-Project/res/Big_Ben.obj"));

	this->listOfLamp.push_back(new Lamp(3.0, 3.4, 5.0));
}

World::~World()
{

}