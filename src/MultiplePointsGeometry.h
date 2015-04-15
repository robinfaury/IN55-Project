#ifndef _MULTIPLEPOINTSGEOMETRY_H
#define _MULTIPLEPOINTSGEOMETRY_H

#include "Geometry.h"

class MultiplePointsGeometry: public Geometry
{
private:
	
protected:
	std::vector<glm::vec3> vertex;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;

	MultiplePointsGeometry();

public:
	MultiplePointsGeometry(std::string name);

	void loadOnGraphicCard();

	std::vector<glm::vec3>* getVertex() {return &this->vertex;}
	std::vector<glm::vec3>* getNormals() {return &this->normals;}
	std::vector<glm::vec2>* getUvs() {return &this->uvs;}

	void setDrawingMode(GLuint mode) {this->drawingMode = mode;}

	~MultiplePointsGeometry();
};

#endif