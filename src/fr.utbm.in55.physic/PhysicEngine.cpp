#include "PhysicEngine.h"

PhysicEngine::PhysicEngine()
{
	this->gravity = -9.80665f;
}

void PhysicEngine::compute(std::vector<PhysicalObject*>* staticObjects,	std::vector<PhysicalObject*>* dynamicObjects)
{
	for (std::vector<PhysicalObject*>::iterator worldObject = dynamicObjects->begin(); worldObject != dynamicObjects->end(); ++worldObject)
	{
		if ((*worldObject)->getPosition().y > 0.0f)
			(*worldObject)->translate(0.0f, 0.01f*this->gravity, 0.0f);
	}
}

PhysicEngine::~PhysicEngine()
{

}