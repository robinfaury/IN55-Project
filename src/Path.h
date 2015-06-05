#ifndef PATH_H_
#define PATH_H_

#include <vector>
#include <glm.hpp>

class Path
{
private:
	std::vector<glm::vec3> controlPoint;

public:
	Path();
	
	void addControlPoint(glm::vec3 point) {this->controlPoint.push_back(point);}

	~Path();

};

#endif