#ifndef _LOD_H
#define _LOD_H

#include "Componant.h"


class LOD: public Componant
{
private:

public:
	LOD();

	virtual void apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale);

	~LOD();

};

#endif