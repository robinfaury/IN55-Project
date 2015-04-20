#include "GraphicObject3D.h"

GraphicObject3D::GraphicObject3D()
{

}

GraphicObject3D::GraphicObject3D(GlobalInformation* globalInformation, std::string name) : Object3D(name)
{
	this->globalInformation = globalInformation;
}

void GraphicObject3D::addGraphicRendererComponant(Material* material)
{
	GraphicRenderer* renderer = new GraphicRenderer(this->globalInformation->getCurrentCamera());
	renderer->setGeometryToDraw(this->currentGeometry);
	renderer->setMaterial(material);
	this->componants.push_back(renderer);
}

void GraphicObject3D::addPhysicComponant(bool dynamic)
{
	if (dynamic)
		this->componants.push_back(new Dynamic());
	else
		this->componants.push_back(new Static());
}

void GraphicObject3D::update()
{
	for (std::vector<GraphicComponant*>::iterator currentComponent = this->componants.begin(); currentComponent != this->componants.end(); ++currentComponent)
		(*currentComponent)->apply(this->transform.getPosition(), this->transform.getRotation(), this->transform.getScaling());
}

GraphicObject3D::~GraphicObject3D()
{

}