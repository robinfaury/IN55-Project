#ifndef _MATERIAL_H
#define _MATERIAL_H

#include <glm.hpp>

#include "Object.h"
#include "Shader.h"
#include "Texture.h"

class Material: public Object
{
private:
	Shader* shader;
	Texture* texture;
	glm::vec3 color;

	Material();

public:
	Material(std::string name, Shader* shader = NULL);

	void setTexture(Texture* texture) {this->texture = texture;}
	void setColor(float r, float g, float b) {this->color = glm::vec3(r, g, b);}

	Shader* getShader() {return this->shader;}
	Texture* getTexture() {return this->texture;}
	glm::vec3 getColor() {return this->color;}

	~Material();
};

#endif