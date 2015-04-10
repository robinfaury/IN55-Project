#include "Texture.h"

Texture::Texture(std::string filename)
{
	this->RGBTexture = new sf::Texture();
	this->RGBTexture->loadFromFile(filename);
	this->RGBTexture->setSmooth(true);
}

Texture::~Texture()
{
	delete this->RGBTexture;
}