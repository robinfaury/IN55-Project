#ifndef _GRAPHICOBJECT3D_H
#define _GRAPHICOBJECT3D_H

#include "Geometry.h"
#include "GraphicRenderer.h"
#include "LOD.h"
#include "ParticleSystem.h"
#include "Object3D.h"
#include "GlobalInformation.h"

class GraphicObject3D: public Object3D
{
private:

protected: 
	Geometry* currentGeometry;
	GlobalInformation* globalInformation;
	std::vector<GraphicComponant*> graphicComponant;

	GraphicObject3D();
    
public:
	GraphicObject3D(GlobalInformation* globalInformation, std::string name);
    
	void addGraphicRendererComponant(Material* material);
	void addLODComponant() {this->graphicComponant.push_back(new LOD());}
	ParticleSystem* addParticleSystemComponant(int nbParticles, Material* material, bool continuous = true);

	void setCurrentGeometry(Geometry* geometry) {this->currentGeometry = geometry;}

    virtual void update();

	~GraphicObject3D();
};

#endif