#ifndef _OBJECT_H
#define _OBJECT_H

#include <string>

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