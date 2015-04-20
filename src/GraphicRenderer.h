#ifndef _GRAPHICRENDERER_H
#define _GRAPHICRENDERER_H

#include "GraphicComponant.h"
#include "Material.h"
#include "Camera.h"

class GraphicRenderer: public GraphicComponant
{
private:
	Geometry* geometryToDraw;
	Material* material;
	Camera* currentCamera;

	GraphicRenderer();

public:
	GraphicRenderer(Camera* camera);
	
	virtual void apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale);

	void setGeometryToDraw(Geometry* geometry) {this->geometryToDraw = geometry;}
	void setMaterial(Material* material) {this->material = material;}

	~GraphicRenderer();
};

#endif 