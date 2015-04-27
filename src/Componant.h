#ifndef COMPONANT_H_
#define COMPONANT_H_

#include <glm.hpp>

class Componant
{
private:

public:
	Componant();
	
	virtual void apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale) = 0;

	~Componant();
	
};

#endif