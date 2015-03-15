#include "EventStyle.h"

EventStyle::EventStyle()
{
	this->world = NULL;
	this->window = NULL;
}

void EventStyle::interpretEvent(sf::Event e)
{
	switch(e.type)
	{
	case sf::Event::Closed:
		this->window->close();
		break;
	}
}

EventStyle::~EventStyle()
{

}
