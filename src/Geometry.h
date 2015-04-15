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

	~Geometry();
};

#endif //_GEOMETRY_H