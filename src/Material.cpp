#include "Material.h"

Material::Material()
{

}

Material::Material(Shader* shader, std::string name) : Object(name)
{
	this->shader = shader;
	this->texture = NULL;
}

Material::~Material()
{

}
