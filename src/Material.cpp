#include "Material.h"

Material::Material()
{

}

Material::Material(Shader* shader, std::string name) : Object(name)
{
	this->shader = shader;
	this->texture = NULL;
	this->color = glm::vec3(1.0f, 1.0f, 1.0f);
}

Material::~Material()
{

}
