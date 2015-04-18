#include "Object3D.h"

Object3D::Object3D()
{

}

Object3D::Object3D(GlobalInformation* globalInformation, Geometry* currentGeometry, std::string name) : Object(name)
{
	this->globalInformation = globalInformation;
	this->currentGeometry = currentGeometry;
}

void Object3D::addGraphicRendererComponant(Material* material)
{
	GraphicRenderer* renderer = new GraphicRenderer(this->globalInformation);
	renderer->setGeometryToDraw(this->currentGeometry);
	renderer->setMaterial(material);
	this->componants.push_back(renderer);
}

void Object3D::addPhysicComponant(bool dynamic)
{
	if (dynamic)
		this->componants.push_back(new Dynamic());
	else
		this->componants.push_back(new Static());
}

void Object3D::translate(float x, float y, float z)
{
	this->transform.translate(x, y, z);
}

void Object3D::rotate(float alpha, float x, float y, float z)
{
	this->transform.rotate(alpha, glm::vec3(x, y, z));
}

void Object3D::scale(float x, float y, float z)
{
	this->transform.scale(x, y, z);
}

void Object3D::setPosition(float x, float y, float z)
{
	this->transform.setPosition(glm::vec3(x, y, z));
}

void Object3D::setRotation(float alpha, float x, float y, float z)
{
	this->transform.setRotation(alpha, glm::vec3(x, y, z), false);
}

void Object3D::setScaling(float x, float y, float z)
{
	this->transform.setScaling(glm::vec3(x, y, z));
}

void Object3D::update()
{
	for (std::vector<Componant*>::iterator currentComponent = this->componants.begin(); currentComponent != this->componants.end(); ++currentComponent)
		(*currentComponent)->apply(this->transform.getPosition(), this->transform.getRotation(), this->transform.getScaling());
}

Object3D::~Object3D()
{

}