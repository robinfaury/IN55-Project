#include "PhysicalObject.h"

PhysicalObject::PhysicalObject() : Object3D()
{
	this->visible = false;
	this->dynamic = false;
	this->material = NULL;
	this->currentGeometry = NULL;
}

PhysicalObject::PhysicalObject(float x, float y, float z) : Object3D(x, y, z)
{
	this->visible = false;
	this->dynamic = false;
	this->material = NULL;
	this->currentGeometry = NULL;
}

PhysicalObject::PhysicalObject(Material* material, bool isDynamic) : Object3D()
{
	this->visible = true;
	this->dynamic = isDynamic;
	this->material = material;
	this->currentGeometry = NULL;
}

PhysicalObject::PhysicalObject(Material* material, float x, float y, float z, bool isDynamic) : Object3D(x, y, z)
{
	this->visible = true;
	this->dynamic = isDynamic;
	this->material = material;
	this->currentGeometry = NULL;
}

PhysicalObject::PhysicalObject(Material* material, Geometry* geometry, bool isDynamic) : Object3D()
{
	this->visible = true;
	this->dynamic = isDynamic;
	this->material = material;
	this->geometrys.push_back(geometry);
	this->currentGeometry = geometry;
}

PhysicalObject::PhysicalObject(Material* material, Geometry* geometry, float x, float y, float z, bool isDynamic) : Object3D(x, y, z)
{
	this->visible = true;
	this->dynamic = isDynamic;
	this->material = material;
	this->geometrys.push_back(geometry);
	this->currentGeometry = geometry;
}

void PhysicalObject::draw ()
{
	GLuint programID = this->material->getShader()->getProgramID();
	glm::vec3 pos = this->transform.getPosition();
	glm::vec3 scale = this->transform.getScaling();
	glUniform3f(glGetUniformLocation(programID, "ObjectPosition"), pos.x, pos.y, pos.z);
	glUniform3f(glGetUniformLocation(programID, "ObjectScale"), scale.x, scale.y, scale.z);
	
	if (this->material->getTexture() != NULL)
		sf::Texture::bind(this->material->getTexture()->getRGBTexture());
	glUniform1i(glGetUniformLocation(programID, "isTexture"), (this->material->getTexture() == NULL)? 0 : 1);
	
	this->currentGeometry->draw(programID);

	if (this->material->getTexture() != NULL)
		sf::Texture::bind(NULL);
}

void PhysicalObject::translate(float x, float y, float z)
{
	this->transform.translate(x, y, z);
}

void PhysicalObject::scale(float x, float y, float z)
{
	this->transform.scale(x, y, z);
}

void PhysicalObject::rescale(float x, float y, float z)
{
	this->transform.rescale(x, y, z);
}

void PhysicalObject::LOD (glm::vec3 positionCamera)
{
}

PhysicalObject::~PhysicalObject()
{

}