#ifndef MESH_H_
#define MESH_H_

#include <vector>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <SFML/Graphics.hpp>

#include "Shader.h"


#ifndef BUFFER_OFFSET
	#define	BUFFER_OFFSET(offset) ((char*)NULL + (offset))
#endif

class Mesh
{
protected:
	Shader* shader;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	glm::vec3 color;

	GLuint vertexBufferID;
	GLuint normalBufferID;
	GLuint VAOID;

	bool loaded;
	
	void loadMesh();

public:
	Mesh();
	Mesh(const char* filename);
	Mesh(const char* filename, Shader* shader);
	
	void loadOBJ(const char* filename);
	void draw(glm::mat4 &model, glm::mat4 &view, glm::mat4 &projection);

	bool isLoaded() {return this->loaded;}

	void setShader(Shader* shader) {this->shader = shader;}

	~Mesh();
};

#endif