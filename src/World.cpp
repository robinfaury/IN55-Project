#include "World.h"

World::World()
{
}

void World::createScene()
{
	this->listOfShader.push_back(new Shader("res/shader/basic.vert", "res/shader/basic.frag"));
	this->listOfMesh.push_back(new Mesh("res/cube_n.obj", this->listOfShader.at(0)));
	//this->listOfMesh.push_back(new Mesh("res/Big_Ben.obj", this->listOfShader.at(0)));
}

World::~World()
{

}