#ifndef LAMP_H_
#define LAMP_H_

#include <glm.hpp>

class Lamp
{
private:
	glm::vec3 position;
	glm::vec3 color;
	float ambiant;
	float diffuse;
	float specular;

public:
	Lamp();
	Lamp(float x, float y, float z);
	Lamp(float x, float y, float z, float r, float g, float b);
	Lamp(float x, float y, float z, float r, float g, float b, float ambiant, float diffuse, float specular);

	void setPosition(float x, float y, float z);
	void setColor(float r, float g, float b);
	void setAmbiant(float a);
	void setDiffuse(float d);
	void setSpecular(float s);
	glm::vec3* getPosition();
	glm::vec3* getColor();
	float getAmbiant();
	float getDiffuse();
	float getSpecular();
	
	~Lamp();
};

#endif