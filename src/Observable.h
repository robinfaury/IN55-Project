#pragma once

#include <string>
#include <set>
#include "IObserver.h"

using namespace std;

typedef int Info;

class Observable
{
private:
	set<IObserver*> list_observers;

public:
	Observable();
	~Observable();
	void notify(string data) const;
	void addObserver(IObserver* observer);
	void removeObserver(IObserver* observer);
};