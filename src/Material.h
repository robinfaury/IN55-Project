#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "Object.h"
#include "Shader.h"
#include "Texture.h"

class Material: public Object
{
private:
	Shader* shader;
	Texture* texture;

	Material();

public:
	Material(Shader* shader, std::string name);

	void setTexture(Texture* texture) {this->texture = texture;}

	Shader* getShader() {return this->shader;}
	Texture* getTexture() {return this->texture;}

	~Material();
};

#endif