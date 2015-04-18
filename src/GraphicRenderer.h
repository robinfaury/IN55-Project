#ifndef _GRAPHICRENDERER_H
#define _GRAPHICRENDERER_H

#include "Componant.h"
#include "Material.h"

class GraphicRenderer: public Componant
{
private:
	Geometry* geometryToDraw;
	Material* material;

	GraphicRenderer();

public:
	GraphicRenderer(GlobalInformation* globalInformation);
	
	virtual void apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale);

	void setGeometryToDraw(Geometry* geometry) {this->geometryToDraw = geometry;}
	void setMaterial(Material* material) {this->material = material;}

	~GraphicRenderer();
};

#endif 