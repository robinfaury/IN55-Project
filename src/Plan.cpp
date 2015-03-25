#include "plan.h"

Plan::Plan()
{
	init();
	this->vertices.push_back(glm::vec3(1.0, 0.0, 1.0));
	this->vertices.push_back(glm::vec3(1.0, 0.0, -1.0));
	this->vertices.push_back(glm::vec3(-1.0, 0.0, -1.0));

	this->vertices.push_back(glm::vec3(-1.0, 0.0, 1.0));
	this->vertices.push_back(glm::vec3(1.0, 0.0, 1.0));
	this->vertices.push_back(glm::vec3(-1.0, 0.0, -1.0));

	for (int i=0; i<6; ++i)
		this->normals.push_back(glm::vec3(0.0, 1.0, 0.0));

	computeNormalOnVertex();

	loadVBO();
}

Plan::~Plan()
{
}