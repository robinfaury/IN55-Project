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
	this->graphicComponant.push_back(renderer);
}

ParticleSystem* GraphicObject3D::addParticleSystemComponant(int nbParticuleMax, Material* material, Geometry* emitterGeometry, bool continuous)
{
	ParticleSystem* ps = new ParticleSystem(nbParticuleMax, material, emitterGeometry, continuous);
	this->graphicComponant.push_back(ps);
	return ps;
}

void GraphicObject3D::update()
{
	Object3D::update();
	for (std::vector<GraphicComponant*>::iterator currentComponent = this->graphicComponant.begin(); currentComponent != this->graphicComponant.end(); ++currentComponent)
		(*currentComponent)->apply(this->transform.trackPosition(), this->transform.trackRotation(), this->transform.trackScaling(), this->globalInformation);
}

GraphicObject3D::~GraphicObject3D()
{

}