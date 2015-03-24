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
private:
	static int ID;
	const int currentID;

protected:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> normalsOnVetices;
	std::vector<glm::vec2> uvs;
	glm::vec3 color;
	glm::vec3 colorID;
	sf::Texture* texture;
	glm::mat4 transform;

	GLuint VBO_Vertices;
	GLuint VBO_Normals;
	GLuint VAO_Mesh;

	GLuint VBO_NormalsOnVetices;
	GLuint VAO_Normals;

	bool loaded;
	bool drawNormal;
	
	void init();
	void loadMesh();

public:
	Mesh();
	Mesh(const char* filename);
	
	void loadOBJ(const char* filename);
	void draw(GLuint shaderID);

	void translate(glm::vec3 translation);
	void scale(glm::vec3 scaling);
	void rotate(float alpha, glm::vec3 axis, bool radian = 1);
	
	bool isLoaded() {return this->loaded;}
	void enableNormal() {this->drawNormal = true;}
	void disableNormal() {this->drawNormal = false;}

	void setColor(glm::vec3 color) {this->color = color;}
	void setTexture(sf::Texture* texture) {this->texture = texture;}

	~Mesh();
};

#endif