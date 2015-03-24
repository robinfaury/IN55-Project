#pragma once

#include <string>
#include "SFML\Graphics.hpp"


using namespace std;

class Button
{
public:
	Button(int x, int y, string text, sf::Font font, sf::Color color, sf::Color colorActivated, int length = 100, int height = 20);
	~Button();

	sf::Text* getText();
	void setText(string text);

	sf::Color getColor();
	sf::Color getColorActivated();
	void activated();
	
	void draw(sf::RenderWindow* window);

protected:
	sf::RectangleShape m_rect;
	sf::Color m_color;
	sf::Color m_color_activated;
	sf::Text m_text;

	bool m_activated;

	void updateTextPos();
};

