#ifndef IOBSERVERMOUSEMOVE_H_
#define IOBSERVERMOUSEMOVE_H_

class IObserverMouseMove
{
public:
	virtual void update(float dx, float dy) = 0;
};

#endif