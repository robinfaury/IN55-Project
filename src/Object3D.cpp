#include "Object3D.h"


Object3D::Object3D()
{
	init();
}

void Object3D::init()
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
	this->texture = NULL;
	this->drawingMode = GL_TRIANGLES;
}

void Object3D::loadVBO()
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

void Object3D::draw(GLuint shaderID)
{
	if (this->texture != NULL)
		sf::Texture::bind(this->texture);
	glUniformMatrix4fv(glGetUniformLocation(shaderID, "Transform"), 1, GL_FALSE, &this->transform[0][0]);
	glUniform3f(glGetUniformLocation(shaderID, "ObjectColor"), this->color.x, this->color.y, this->color.z);
	glUniform3f(glGetUniformLocation(shaderID, "ObjectColorID"), this->colorID.x, this->colorID.y, this->colorID.z);
	glUniform1i(glGetUniformLocation(shaderID, "isNormals"), !this->normals.empty());
	glUniform1i(glGetUniformLocation(shaderID, "isTexture"), (this->texture == NULL)? 0 : 1);
	glBindVertexArray(this->VAO_Mesh);
		glDrawArrays(this->drawingMode, 0, this->vertices.size());
	glBindVertexArray(0);
	if (this->texture != NULL)
		sf::Texture::bind(NULL);

	if (this->drawNormal)
	{
		glBindVertexArray(this->VAO_Normals);
			glDrawArrays(GL_LINES, 0, this->normalsOnVetices.size());
		glBindVertexArray(0);
	}
}

void Object3D::computeNormalOnVertex()
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

void Object3D::translate(glm::vec3 translation)
{
	this->transform[3][0] += translation[0];
	this->transform[3][1] += translation[1];
	this->transform[3][2] += translation[2];
}

void Object3D::scale(glm::vec3 scaling)
{
	this->transform[0][0] *= scaling[0];
	this->transform[1][1] *= scaling[1];
	this->transform[2][2] *= scaling[2];
}

void Object3D::rotate(float alpha, glm::vec3 axis, bool radian)
{
	if (!radian)
		alpha = 3.14159265359 * alpha / 180.0;
	glm::normalize(axis);
	float c = cos(alpha), s = sin(alpha);
	this->transform[0][0] = axis.x*axis.x + (1 - axis.x*axis.x)*c;		this->transform[1][0] = axis.x*axis.y*(1-c) - axis.z*s;				this->transform[2][0] = axis.x*axis.z*(1-c) + axis.y*s;
	this->transform[0][1] = axis.x*axis.y*(1-c) + axis.z*s;				this->transform[1][1] = axis.y*axis.y + (1 - axis.y*axis.y)*c;		this->transform[2][1] = axis.y*axis.z*(1-c) - axis.x*s;
	this->transform[0][2] = axis.x*axis.z*(1-c) - axis.y*s;				this->transform[1][2] = axis.y*axis.z*(1-c) + axis.x*s;				this->transform[2][2] = axis.z*axis.z + (1 - axis.z*axis.z)*c;
}

Object3D::~Object3D()
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