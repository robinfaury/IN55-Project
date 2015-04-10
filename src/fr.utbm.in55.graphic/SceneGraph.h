#ifndef _SCENEGRAPH_H
#define _SCENEGRAPH_H

#include "Node.h"

class SceneGraph
{
private: 
    Node root;
public: 
    
    Node* getRoot();
};

#endif