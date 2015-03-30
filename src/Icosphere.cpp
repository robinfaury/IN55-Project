#include "Icosphere.h"

Icosphere::Icosphere()
{
	init();
	
	float t = (1.0 + sqrt(5.0)) / 4.0;

	std::vector<glm::vec3> vertex;
	
	vertex.push_back(glm::vec3(-1.0, t, 0.0));
	vertex.push_back(glm::vec3(1.0, t, 0.0));
	vertex.push_back(glm::vec3(-1.0, -t, 0.0));
	vertex.push_back(glm::vec3(1.0, -t, 0.0));

	vertex.push_back(glm::vec3(0.0, -1.0, t));
	vertex.push_back(glm::vec3(0.0, 1.0, t));
	vertex.push_back(glm::vec3(0.0, -1.0, -t));
	vertex.push_back(glm::vec3(0.0, 1.0, -t));

	vertex.push_back(glm::vec3(t, 0.0, -1.0));
	vertex.push_back(glm::vec3(t, 0.0, 1.0));
	vertex.push_back(glm::vec3(-t, 0.0, -1.0));
	vertex.push_back(glm::vec3(-t, 0.0, 1.0));


	this->vertices.push_back(vertex[0]);
	this->vertices.push_back(vertex[11]);
	this->vertices.push_back(vertex[5]);

	this->vertices.push_back(vertex[0]);
	this->vertices.push_back(vertex[5]);
	this->vertices.push_back(vertex[1]);

	this->vertices.push_back(vertex[0]);
	this->vertices.push_back(vertex[1]);
	this->vertices.push_back(vertex[7]);

	this->vertices.push_back(vertex[0]);
	this->vertices.push_back(vertex[7]);
	this->vertices.push_back(vertex[10]);

	this->vertices.push_back(vertex[0]);
	this->vertices.push_back(vertex[10]);
	this->vertices.push_back(vertex[11]);

	
	this->vertices.push_back(vertex[1]);
	this->vertices.push_back(vertex[5]);
	this->vertices.push_back(vertex[9]);

	this->vertices.push_back(vertex[5]);
	this->vertices.push_back(vertex[11]);
	this->vertices.push_back(vertex[4]);

	this->vertices.push_back(vertex[11]);
	this->vertices.push_back(vertex[10]);
	this->vertices.push_back(vertex[2]);

	this->vertices.push_back(vertex[10]);
	this->vertices.push_back(vertex[7]);
	this->vertices.push_back(vertex[6]);

	this->vertices.push_back(vertex[7]);
	this->vertices.push_back(vertex[1]);
	this->vertices.push_back(vertex[8]);


	this->vertices.push_back(vertex[3]);
	this->vertices.push_back(vertex[9]);
	this->vertices.push_back(vertex[4]);

	this->vertices.push_back(vertex[3]);
	this->vertices.push_back(vertex[4]);
	this->vertices.push_back(vertex[2]);

	this->vertices.push_back(vertex[3]);
	this->vertices.push_back(vertex[2]);
	this->vertices.push_back(vertex[6]);

	this->vertices.push_back(vertex[3]);
	this->vertices.push_back(vertex[6]);
	this->vertices.push_back(vertex[8]);

	this->vertices.push_back(vertex[3]);
	this->vertices.push_back(vertex[8]);
	this->vertices.push_back(vertex[9]);


	this->vertices.push_back(vertex[4]);
	this->vertices.push_back(vertex[9]);
	this->vertices.push_back(vertex[5]);

	this->vertices.push_back(vertex[2]);
	this->vertices.push_back(vertex[4]);
	this->vertices.push_back(vertex[11]);

	this->vertices.push_back(vertex[6]);
	this->vertices.push_back(vertex[2]);
	this->vertices.push_back(vertex[10]);

	this->vertices.push_back(vertex[8]);
	this->vertices.push_back(vertex[6]);
	this->vertices.push_back(vertex[7]);

	this->vertices.push_back(vertex[9]);
	this->vertices.push_back(vertex[8]);
	this->vertices.push_back(vertex[1]);

	for (int i=0; i<this->vertices.size(); ++i)
		this->normals.push_back(glm::normalize(this->vertices[i]));

	computeNormalOnVertex();

	loadVBO();
}

Icosphere::~Icosphere()
{
}