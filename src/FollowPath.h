#ifndef FOLLOWPATH_H_
#define FOLLOWPATH_H_

#include "Componant.h"

class FollowPath : public Componant
{
private:
	unsigned int time;
	

public:
	FollowPath();

	virtual void apply(glm::vec3* position, glm::mat3* rotation, glm::vec3* scale);

	~FollowPath();
};

#endif