#include "Material.h"

Material::Material(Shader* shader)
{
	this->shader = shader;
	this->texture = NULL;
}

Material::Material(Shader* shader, Texture* texture)
{
	this->shader = shader;
	this->texture = texture;
}


void Material::setShader(Shader* shader)
{
	this->shader = shader;
}

void Material::setTexture(Texture* texture)
{
	this->texture = texture;
}

Shader* Material::getShader()
{
	return this->shader;
}

Texture* Material::getTexture()
{
	return texture;
}


Material::~Material()
{

}