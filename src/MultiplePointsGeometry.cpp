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

MultiplePointsGeometry::~MultiplePointsGeometry()
{

}
