#ifndef INTERACTIONWINDOW_H_
#define INTERACTIONWINDOW_H_

#include <vector>
#include "SFML\Graphics.hpp"
#include "Button.h"
#include "Object3D.h"


using namespace std;

enum FONT_TYPE
{
	WALKWAY = 0
};

class InteractionWindow
{
protected:

	sf::RenderWindow m_window;

	bool m_running;

	vector<sf::Font> m_fonts;
	vector<Button*> m_buttons;

public:
	InteractionWindow(sf::VideoMode videoMode);
	~InteractionWindow();

	// True if the interaction window is running (still open)
	bool isRunning();

	// Closes the interaction window
	void close();

	// Goes through all events that occured since last frame, and resolves them
	void processEvents();

	void draw();

	//TODO: add buttons

};

#endif

