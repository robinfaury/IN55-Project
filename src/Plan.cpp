#include "plan.h"

Plan::Plan() : Object3D()
{
	init();

	this->drawingMode = GL_QUADS;

	this->vertices.push_back(glm::vec3(1.0, 0.0, 1.0));
	this->vertices.push_back(glm::vec3(1.0, 0.0, -1.0));
	this->vertices.push_back(glm::vec3(-1.0, 0.0, -1.0));
	this->vertices.push_back(glm::vec3(-1.0, 0.0, 1.0));

	for (int i=0; i<this->vertices.size(); ++i)
		this->normals.push_back(glm::vec3(0.0, 1.0, 0.0));

	this->uvs.push_back(glm::vec2(1.0, 0.0));
	this->uvs.push_back(glm::vec2(1.0, 1.0));
	this->uvs.push_back(glm::vec2(0.0, 1.0));
	this->uvs.push_back(glm::vec2(0.0, 0.0));

	computeNormalOnVertex();

	loadVBO();
}

Plan::~Plan()
{
}