#include "Geometry.h"

Geometry::Geometry()
{
	init();
}

void Geometry::init()
{
	this->VBO_Vertices = 0;
	this->VBO_Normals = 0;
	this->VBO_UVs = 0;
	this->VBO_NormalsOnVetices = 0;
	this->VAO_Mesh = 0;
	this->VAO_Normals = 0;
	this->color = glm::vec3(1.0, 1.0, 1.0);
	//this->colorID = glm::vec3(((this->currentID & 0x000000FF) >> 0)/255.0, ((this->currentID & 0x0000FF00) >> 8)/255.0, ((this->currentID & 0x00FF0000) >> 16)/255.0);
	this->drawNormal = false;
	this->drawingMode = GL_TRIANGLES;
}

void Geometry::loadVBO()
{
	/***********************VBO Vertices***********************/
	if (glIsBuffer(this->VBO_Vertices) == GL_TRUE)
		glDeleteBuffers(1, &this->VBO_Vertices);
	glGenBuffers(1, &this->VBO_Vertices);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Vertices);
		glBufferData(GL_ARRAY_BUFFER, this->vertices.size()*sizeof(glm::vec3), &this->vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/***********************VBO Normals***********************/
	if (!this->normals.empty())
	{
		if (glIsBuffer(this->VBO_Normals) == GL_TRUE)
			glDeleteBuffers(1, &this->VBO_Normals);
		glGenBuffers(1, &this->VBO_Normals);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Normals);
			glBufferData(GL_ARRAY_BUFFER, this->normals.size()*sizeof(glm::vec3), &this->normals[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	/***********************VBO UVs***************************/
	if (!this->uvs.empty())
	{
		if (glIsBuffer(this->VBO_UVs) == GL_TRUE)
			glDeleteBuffers(1, &this->VBO_UVs);
		glGenBuffers(1, &this->VBO_UVs);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO_UVs);
			glBufferData(GL_ARRAY_BUFFER, this->uvs.size()*sizeof(glm::vec2), &this->uvs[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	/***********************VBO NormalsOnVetices***********************/
	if (glIsBuffer(this->VBO_NormalsOnVetices) == GL_TRUE)
		glDeleteBuffers(1, &this->VBO_NormalsOnVetices);
	glGenBuffers(1, &this->VBO_NormalsOnVetices);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_NormalsOnVetices);
		glBufferData(GL_ARRAY_BUFFER, this->normalsOnVetices.size()*sizeof(glm::vec3), &this->normalsOnVetices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/***********************VAO 3DObject***********************/
	if (glIsVertexArray(this->VAO_Mesh == GL_TRUE))
		glDeleteVertexArrays(1, &this->VAO_Mesh);
	glGenVertexArrays(1, &this->VAO_Mesh);
	glBindVertexArray(this->VAO_Mesh);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Vertices);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
			glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Normals);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
			glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		if (!this->uvs.empty())
		{
			glBindBuffer(GL_ARRAY_BUFFER, this->VBO_UVs);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
				glEnableVertexAttribArray(2);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	glBindVertexArray(0);

	/***********************VAO Normals***********************/
	if (glIsVertexArray(this->VAO_Normals == GL_TRUE))
		glDeleteVertexArrays(1, &this->VAO_Normals);
	glGenVertexArrays(1, &this->VAO_Normals);
	glBindVertexArray(this->VAO_Normals);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO_NormalsOnVetices);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
			glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Geometry::draw(GLuint shaderID)
{	
	glUniform3f(glGetUniformLocation(shaderID, "ObjectColor"), this->color.x, this->color.y, this->color.z);
	glUniform3f(glGetUniformLocation(shaderID, "ObjectColorID"), this->colorID.x, this->colorID.y, this->colorID.z);
	glUniform1i(glGetUniformLocation(shaderID, "isNormals"), !this->normals.empty());
	
	glBindVertexArray(this->VAO_Mesh);
		glDrawArrays(this->drawingMode, 0, static_cast<GLsizei>(this->vertices.size()));
	glBindVertexArray(0);

	if (this->drawNormal)
	{
		glBindVertexArray(this->VAO_Normals);
			glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(this->normalsOnVetices.size()));
		glBindVertexArray(0);
	}
}

void Geometry::computeNormalOnVertex()
{
	if (this->normals.size() > 0)
	{
		for (unsigned int i=0; i<this->normals.size(); i++)
		{
			this->normalsOnVetices.push_back(this->vertices[i]);
			this->normalsOnVetices.push_back(this->vertices[i]+this->normals[i]);
		}
	}
}

Geometry::~Geometry()
{
	glDeleteBuffers(1, &this->VBO_Vertices);
	glDeleteBuffers(1, &this->VBO_Normals);
	glDeleteBuffers(1, &this->VBO_NormalsOnVetices);
	glDeleteVertexArrays(1, &this->VAO_Mesh);
	glDeleteVertexArrays(1, &this->VAO_Normals);
	this->vertices.clear();
	this->normals.clear();
	this->normalsOnVetices.clear();
	this->uvs.clear();
}