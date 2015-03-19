#ifndef LAMP_H_
#define LAMP_H_

#include <glm.hpp>

class Lamp
{
private:
	glm::vec3 position;
	glm::vec3 color;
	float ambiant;
	float difuse;
	float specular;

public:
	Lamp();

	void SetPosition(float x, float y, float z);
	void SetColor(float r, float g, float b);
	void SetAmbiant(float a);
	void SetDiffuse(float d);
	void SetSpecular(float s);
	
	~Lamp();
};

#endif