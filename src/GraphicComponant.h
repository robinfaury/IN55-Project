#ifndef _GRAPHICCOMPONANT_H
#define _GRAPHICCOMPONANT_H

#include "Componant.h"
#include "Geometry.h"
#include "GlobalInformation.h"

class GraphicComponant : public Componant
{
private:

protected: 
	virtual void apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale) {}

public:
	GraphicComponant();

	virtual void apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale, GlobalInformation* globalInformation) = 0;
	
	~GraphicComponant();
};

#endif