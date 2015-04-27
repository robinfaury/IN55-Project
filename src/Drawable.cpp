#include "Drawable.h"

Drawable::Drawable()
{
	this->VBO_Stream = 0;
	this->VBO_Vertices = 0;
	this->VBO_Normals = 0;
	this->VBO_UVs = 0;
}

void Drawable::loadOnGraphicCard(GLuint drawingMode, std::vector<glm::vec3>* vertex, std::vector<glm::vec3>* normals, std::vector<glm::vec2>* uvs)
{
	this->drawingMode = drawingMode;
	this->nbVertex = static_cast<GLsizei>(vertex->size());
	createVBO(vertex, normals, uvs);
	createVAO();
}

void Drawable::loadOnGraphicCardStrem(GLuint drawingMode, std::vector<glm::vec3>* vertex)
{
	if (glIsBuffer(this->VBO_Stream) == GL_TRUE)
		glDeleteBuffers(1, &this->VBO_Stream);
	glGenBuffers(1, &this->VBO_Stream);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Stream);
		glBufferData(GL_ARRAY_BUFFER, vertex->size() * 3 * sizeof(GLfloat), NULL, GL_STATIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, vertex->size() * 3 * sizeof(GLfloat), &(*vertex)[0]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	this->drawingMode = drawingMode;
	this->nbVertex = static_cast<GLsizei>(vertex->size());
	createVAO();
}

void Drawable::updateStream(std::vector<glm::vec3>* vertex)
{
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Vertices);
		glBufferData(GL_ARRAY_BUFFER, vertex->size() * 3 * sizeof(GLfloat), NULL, GL_STATIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, vertex->size() * sizeof(GLfloat) * 3, &(*vertex)[0]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
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
	if (normals != NULL && !normals->empty())
	{
		if (glIsBuffer(this->VBO_Normals) == GL_TRUE)
			glDeleteBuffers(1, &this->VBO_Normals);
		glGenBuffers(1, &this->VBO_Normals);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Normals);
			glBufferData(GL_ARRAY_BUFFER, normals->size()*sizeof(glm::vec3), &(*normals)[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	/***********************VBO UVs***************************/
	if (uvs != NULL && !uvs->empty())
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
	if (this->VBO_Stream != 0)
	{
		if (glIsVertexArray(this->VAO == GL_TRUE))
			glDeleteVertexArrays(1, &this->VAO);
		glGenVertexArrays(1, &this->VAO);
		glBindVertexArray(this->VAO);
			glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Vertices);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
				glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		return;
	}
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