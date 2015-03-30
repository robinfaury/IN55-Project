#ifndef IOBSERVER_H_
#define IOBSERVER_H_

#include <iostream>

class IObserver
{
public:
	virtual void update(std::string data) = 0;
};

#endif