#ifndef _PHYSICENGINE_H
#define _PHYSICENGINE_H

#include "../fr.utbm.in55.graphic/SceneGraph.h"
#include "../fr.utbm.in55.graphic/PhysicalObject.h"

class PhysicEngine
{
private: 
	float gravity;
    SceneGraph* sceneGraph;

public:
	PhysicEngine();

	void compute(std::vector<PhysicalObject*>* staticObjects,	std::vector<PhysicalObject*>* dynamicObjects);

	~PhysicEngine();
};

#endif //_PHYSICENGINE_H