#ifndef _OBJECT3D_H
#define _OBJECT3D_H

#include "Transform.h"
#include "Geometry.h"
#include "GraphicRenderer.h"
#include "Dynamic.h"
#include "Static.h"
#include "LOD.h"
#include "ParticleSystem.h"

class Object3D: public Object
{
private:

protected: 
	Transform transform;
	std::vector<Componant*> componants;
	Geometry* currentGeometry;
	GlobalInformation* globalInformation;

	Object3D();
    
public:
	Object3D(GlobalInformation* globalInformation, Geometry* currentGeometry, std::string name);
    
	void addGraphicRendererComponant(Material* material);
	void addPhysicComponant(bool dynamic = false);
	void addLODComponant() {this->componants.push_back(new LOD());}
	void addParticleSystemComponant() {this->componants.push_back(new ParticleSystem());}

    void update();

	~Object3D();
};

#endif