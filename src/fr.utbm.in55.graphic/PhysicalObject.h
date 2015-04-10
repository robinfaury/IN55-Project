#ifndef _PHYSICALOBJECT_H
#define _PHYSICALOBJECT_H

#include <vector>
#include <glm.hpp>

#include "Object3D.h"
#include "Plan.h"
#include "Mesh.h"
#include "Material.h"

class PhysicalObject: public Object3D
{
private: 
    void LOD (glm::vec3 positionCamera);

protected: 
    bool dynamic;
	bool visible;
    std::vector<Geometry*> geometrys;
    Geometry* currentGeometry;
	Material* material;

public: 
	PhysicalObject();
	PhysicalObject(float x, float y, float z);
	PhysicalObject(Material* material, bool isDynamic = false);
	PhysicalObject(Material* material, float x, float y, float z, bool isDynamic = false);
	PhysicalObject(Material* material, Geometry* geometry, bool isDynamic = false);
	PhysicalObject(Material* material, Geometry* geometry, float x, float y, float z, bool isDynamic = false);

    void draw();
	void translate(float x, float y, float z);
	void rescale(float x, float y, float z);
	void scale(float x, float y, float z);

	Material* getMaterial() {return this->material;}

	bool isDynamic() {return this->dynamic;}
	bool isVisible() {return this->visible;}

	~PhysicalObject();
};

#endif