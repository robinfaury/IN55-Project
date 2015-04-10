#ifndef _NODE_H
#define _NODE_H

#include <vector>

#include "Transform.h"
#include "Object3D.h"

class Node
{
private: 
    Transform transform;
    std::vector<Node*> nodes;
    std::vector<Object3D*> Objects3D;

public:
	Node();

	~Node();
};

#endif