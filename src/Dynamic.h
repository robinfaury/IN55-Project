#ifndef _DYNAMIC_H
#define _DYNAMIC_H

#include "Physic.h"


class Dynamic: public Physic
{
private:

public:
	Dynamic();

	virtual void apply();

	~Dynamic();
};

#endif //_DYNAMIC_H