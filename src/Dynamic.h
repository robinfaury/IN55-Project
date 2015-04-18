#ifndef _DYNAMIC_H
#define _DYNAMIC_H

#include "Physic.h"


class Dynamic: public Physic
{
private:

public:
	Dynamic();

	virtual void apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale);

	~Dynamic();
};

#endif //_DYNAMIC_H