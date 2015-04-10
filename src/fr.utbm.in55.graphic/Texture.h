#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <string>
#include <SFML/Graphics.hpp>

class Texture
{
private:
	sf::Texture* RGBTexture;

	Texture() {}

public:
	Texture(std::string filename);

	sf::Texture* getRGBTexture() {return this->RGBTexture;}

	~Texture();
};

#endif