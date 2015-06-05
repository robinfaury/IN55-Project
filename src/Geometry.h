#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include "Object.h"
#include "Drawable.h"

class Geometry: public Object
{
private:

protected:
	Drawable drawable;
	GLuint drawingMode;

	Geometry();
    
public:
	Geometry(std::string name);

	Drawable* getDrawable() {return &this->drawable;}

	GLuint getDrawingMode() {return this->drawingMode;}

	virtual std::pair<glm::vec3, glm::vec3> getRandPosOnMesh() = 0;
	virtual int getNbGeometry() = 0;
	virtual std::pair<std::vector<glm::vec3>, glm::vec3> getGeometryAndNormal(int id) = 0;

	~Geometry();
};

#endif //_GEOMETRY_H