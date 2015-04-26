#ifndef _OBJECT_H
#define _OBJECT_H

#include <string>
#include <iostream>

class Object
{
protected: 
    std::string name;

	Object();
	Object(std::string name);

public:
	
	~Object();
};

#endif 