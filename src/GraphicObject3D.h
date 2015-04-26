#ifndef _GRAPHICOBJECT3D_H
#define _GRAPHICOBJECT3D_H

#include "Geometry.h"
#include "GraphicRenderer.h"
#include "Dynamic.h"
#include "Static.h"
#include "LOD.h"
#include "ParticleSystem.h"
#include "GlobalInformation.h"
#include "Object3D.h"

class GraphicObject3D: public Object3D
{
private:

protected: 
	std::vector<GraphicComponant*> componants;
	Geometry* currentGeometry;
	GlobalInformation* globalInformation;

	GraphicObject3D();
    
public:
	GraphicObject3D(GlobalInformation* globalInformation, std::string name);
    
	void addGraphicRendererComponant(Material* material);
	void addPhysicComponant(bool dynamic = false);
	void addLODComponant() {this->componants.push_back(new LOD());}
	void addParticleSystemComponant(int nbParticles, bool continuous = true) {this->componants.push_back(new ParticleSystem(nbParticles, continuous));}

	void setCurrentGeometry(Geometry* geometry) {this->currentGeometry = geometry;}

    void update();

	~GraphicObject3D();
};

#endif