#include "Texture.h"

Texture::Texture()
{
	this->RGBAImage = NULL;
}

Texture::Texture(std::string filenameRGBAImage, std::string name) : Object(name)
{
	this->RGBAImage = new sf::Image();
	this->RGBAImage->loadFromFile(filenameRGBAImage);
	
	glGenTextures(1, &this->textureID);
	glBindTexture(GL_TEXTURE_2D, this->textureID);
	glTexImage2D(
		GL_TEXTURE_2D, 0, GL_RGBA,
		this->RGBAImage->getSize().x, this->RGBAImage->getSize().y,
		0,
		GL_RGBA, GL_UNSIGNED_BYTE, this->RGBAImage->getPixelsPtr()
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{
	if (this->RGBAImage != NULL)
		delete this->RGBAImage;
}