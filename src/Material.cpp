#include "Material.h"

Material::Material()
{

}

Material::Material(std::string name, Shader* shader) : Object(name)
{
	if (this->shader != NULL)
		this->shader = shader;
	this->texture = NULL;
	this->color = glm::vec3(1.0f, 1.0f, 1.0f);
}

Material::~Material()
{

}
