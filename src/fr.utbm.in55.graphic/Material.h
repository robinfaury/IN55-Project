#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "Shader.h"
#include "Texture.h"

class Material
{
private:
	Shader* shader;
	Texture* texture;

	Material() {}

public:
	Material(Shader* shader);
	Material(Shader* shader, Texture* texture);

	void setShader(Shader* shader);
	void setTexture(Texture* texture);
	Shader* getShader();
	Texture* getTexture();

	~Material();
};

#endif 