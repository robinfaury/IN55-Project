#ifndef _PLAN_H
#define _PLAN_H

#include "MultiplePointsGeometry.h"


class Plan: public MultiplePointsGeometry
{
private:
	Plan();

public:
	Plan(std::string name);

	~Plan();
};

#endif