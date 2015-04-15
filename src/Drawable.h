#ifndef _DRAWABLE_H
#define _DRAWABLE_H

#include <vector>

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <glm.hpp>

#ifndef BUFFER_OFFSET
	#define	BUFFER_OFFSET(offset) ((char*)NULL + (offset))
#endif

class Drawable
{
private:
	GLuint VBO_Vertices;
	GLuint VBO_Normals;
	GLuint VBO_UVs;
	GLuint VAO;

	GLuint drawingMode;
	GLsizei nbVertex;
	
	void createVBO(std::vector<glm::vec3>* vertex, std::vector<glm::vec3>* normals, std::vector<glm::vec2>* uvs);
	void createVAO();

public:
	Drawable();

	void loadOnGraphicCard(std::vector<glm::vec3>* vertex, std::vector<glm::vec3>* normals, std::vector<glm::vec2>* uvs, GLuint drawingMode);
	void draw();

	~Drawable();
};

#endif //_DRAWABLE_H