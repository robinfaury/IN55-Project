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

void Object3D::update()
{
	for (std::vector<Componant*>::iterator currentComponent = this->componants.begin(); currentComponent != this->componants.end(); ++currentComponent)
		(*currentComponent)->apply();
}

Object3D::~Object3D()
{

}