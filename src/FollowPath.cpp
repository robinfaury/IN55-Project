#include "FollowPath.h"


FollowPath::FollowPath()
{
	this->time = 0;
}

void FollowPath::apply(glm::vec3* position, glm::mat3* rotation, glm::vec3* scale)
{
	++this->time;
}

FollowPath::~FollowPath()
{

}