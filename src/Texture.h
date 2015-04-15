#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "Object.h"

class Texture : public Object
{
private:
	sf::Image* RGBAImage;
	GLuint textureID;
	Texture();

public:
	Texture(std::string filenameRGBAImage, std::string name);

	GLuint getTextureID() {return this->textureID;}

	~Texture();

};

#endif