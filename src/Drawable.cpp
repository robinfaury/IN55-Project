#include "Drawable.h"

Drawable::Drawable()
{
	this->VBO_Vertices = 0;
	this->VBO_Normals = 0;
	this->VBO_UVs = 0;
}

void Drawable::loadOnGraphicCard(std::vector<glm::vec3>* vertex, std::vector<glm::vec3>* normals, std::vector<glm::vec2>* uvs, GLuint drawingMode)
{
	this->drawingMode = drawingMode;
	this->nbVertex = static_cast<GLsizei>(vertex->size());
	createVBO(vertex, normals, uvs);
	createVAO();
}

void Drawable::createVBO(std::vector<glm::vec3>* vertex, std::vector<glm::vec3>* normals, std::vector<glm::vec2>* uvs)
{
	/***********************VBO Vertices***********************/
	if (glIsBuffer(this->VBO_Vertices) == GL_TRUE)
		glDeleteBuffers(1, &this->VBO_Vertices);
	glGenBuffers(1, &this->VBO_Vertices);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Vertices);
		glBufferData(GL_ARRAY_BUFFER, vertex->size()*sizeof(glm::vec3), &(*vertex)[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/***********************VBO Normals***********************/
	if (!normals->empty())
	{
		if (glIsBuffer(this->VBO_Normals) == GL_TRUE)
			glDeleteBuffers(1, &this->VBO_Normals);
		glGenBuffers(1, &this->VBO_Normals);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Normals);
			glBufferData(GL_ARRAY_BUFFER, normals->size()*sizeof(glm::vec3), &(*normals)[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	/***********************VBO UVs***************************/
	if (!uvs->empty())
	{
		if (glIsBuffer(this->VBO_UVs) == GL_TRUE)
			glDeleteBuffers(1, &this->VBO_UVs);
		glGenBuffers(1, &this->VBO_UVs);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO_UVs);
			glBufferData(GL_ARRAY_BUFFER, uvs->size()*sizeof(glm::vec2), &(*uvs)[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}

void Drawable::createVAO()
{
	/***********************VAO 3DObject***********************/
	if (glIsVertexArray(this->VAO == GL_TRUE))
		glDeleteVertexArrays(1, &this->VAO);
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Vertices);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
			glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		if (this->VBO_Normals != 0)
		{
			glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Normals);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
				glEnableVertexAttribArray(1);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		if (this->VBO_UVs != 0)
		{
			glBindBuffer(GL_ARRAY_BUFFER, this->VBO_UVs);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
				glEnableVertexAttribArray(2);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	glBindVertexArray(0);
}

void Drawable::draw()
{
	glBindVertexArray(this->VAO);
		glDrawArrays(this->drawingMode, 0, this->nbVertex);
	glBindVertexArray(0);
}

Drawable::~Drawable()
{

}