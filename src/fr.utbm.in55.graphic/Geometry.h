#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <SFML/Graphics.hpp>
#include <GL/glew.h>

#ifndef BUFFER_OFFSET
	#define	BUFFER_OFFSET(offset) ((char*)NULL + (offset))
#endif

class Geometry
{
private:

protected:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> normalsOnVetices;
	std::vector<glm::vec2> uvs;
	glm::vec3 color;
	glm::vec3 colorID;

	GLuint VBO_Vertices;
	GLuint VBO_Normals;
	GLuint VBO_UVs;
	GLuint VAO_Mesh;

	GLuint VBO_NormalsOnVetices;
	GLuint VAO_Normals;

	bool drawNormal;
	int drawingMode;
	
	void loadVBO();
	void computeNormalOnVertex();

public:
	Geometry();

	void init();
	
	virtual void draw(GLuint shaderID);
	
	void enableNormal() {this->drawNormal = true;}
	void disableNormal() {this->drawNormal = false;}

	void setColor(glm::vec3 color) {this->color = color;}

	~Geometry();
};

#endif