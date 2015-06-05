#include "MultiplePointsGeometry.h"

MultiplePointsGeometry::MultiplePointsGeometry()
{

}

MultiplePointsGeometry::MultiplePointsGeometry(std::string name) : Geometry(name)
{

}

void MultiplePointsGeometry::loadOnGraphicCard()
{
	this->drawable.loadOnGraphicCard(this->drawingMode, &this->vertex, &this->normals, &this->uvs);
}

std::pair<glm::vec3, glm::vec3> MultiplePointsGeometry::getRandPosOnMesh()
{
	std::pair<glm::vec3, glm::vec3> output;

	int id = rand()%getNbGeometry();
	std::pair<std::vector<glm::vec3>, glm::vec3> geo = getGeometryAndNormal(id);

	output.first = geo.first[0] * static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	for (int i=1; i<geo.first.size(); ++i)
		output.first += geo.first[i] * static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	output.second = geo.second;
	return output;
}

int MultiplePointsGeometry::getNbGeometry()
{
	switch(this->drawingMode)
	{
	case GL_LINES:
		return this->vertex.size()/2;
		break;
	case GL_TRIANGLES:
		return this->vertex.size()/3;
		break;
	case GL_QUADS:
		return this->vertex.size()/4;
		break;
	default:
		return this->vertex.size();
		break;
	}
}

std::pair<std::vector<glm::vec3>, glm::vec3> MultiplePointsGeometry::getGeometryAndNormal(int id)
{
	std::pair<std::vector<glm::vec3>, glm::vec3> output;
	switch(this->drawingMode)
	{
	case GL_LINES:
		output.first.push_back(this->vertex[id*2]);
		output.first.push_back(this->vertex[id*2+1]);
		break;
	case GL_TRIANGLES:
		output.first.push_back(this->vertex[id*2]);
		output.first.push_back(this->vertex[id*2+1]);
		output.first.push_back(this->vertex[id*2+2]);
		output.second = glm::cross(this->vertex[id*2+1] - this->vertex[id*2], this->vertex[id*2+2] - this->vertex[id*2]);
		break;
	case GL_QUADS:
		output.first.push_back(this->vertex[id*2]);
		output.first.push_back(this->vertex[id*2+1]);
		output.first.push_back(this->vertex[id*2+2]);
		output.first.push_back(this->vertex[id*2+3]);
		output.second = glm::cross(this->vertex[id*2+1] - this->vertex[id*2], this->vertex[id*2+2] - this->vertex[id*2]);
		break;
	default:
		output.first.push_back(this->vertex[id]);
		break;
	}

	return output;
}

MultiplePointsGeometry::~MultiplePointsGeometry()
{

}
