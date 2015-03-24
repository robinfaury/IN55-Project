#ifndef MESH_H_
#define MESH_H_

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

class Mesh
{
protected:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> normalsOnVetices;
	std::vector<glm::vec2> uvs;
	glm::vec3 color;

	GLuint VBO_Vertices;
	GLuint VBO_Normals;
	GLuint VAO_Mesh;

	GLuint VBO_NormalsOnVetices;
	GLuint VAO_Normals;

	bool loaded;
	bool drawNormal;
	
	void loadMesh();

public:
	Mesh();
	Mesh(const char* filename);
	
	void loadOBJ(const char* filename);
	void draw();

	bool isLoaded() {return this->loaded;}
	void enableNormal() {this->drawNormal = true;}
	void disableNormal() {this->drawNormal = false;}

	~Mesh();
};

#endif