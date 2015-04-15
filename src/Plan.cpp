#include "Plan.h"

Plan::Plan()
{

}

Plan::Plan(std::string name) : MultiplePointsGeometry(name)
{
	this->drawingMode = GL_QUADS;
	this->vertex.push_back(glm::vec3(1.0, 0.0, 1.0));
	this->vertex.push_back(glm::vec3(1.0, 0.0, -1.0));
	this->vertex.push_back(glm::vec3(-1.0, 0.0, -1.0));
	this->vertex.push_back(glm::vec3(-1.0, 0.0, 1.0));

	for (int i=0; i<this->vertex.size(); ++i)
		this->normals.push_back(glm::vec3(0.0, 1.0, 0.0));

	this->uvs.push_back(glm::vec2(1.0, 0.0));
	this->uvs.push_back(glm::vec2(1.0, 1.0));
	this->uvs.push_back(glm::vec2(0.0, 1.0));
	this->uvs.push_back(glm::vec2(0.0, 0.0));
}

Plan::~Plan()
{

}