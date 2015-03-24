#include "Mesh.h"

int Mesh::ID = 0;

Mesh::Mesh() : currentID(ID++)
{
	init();
}

Mesh::Mesh(const char* filename) : currentID(ID++)
{
	init();
	loadOBJ(filename);
}

void Mesh::init()
{
	this->VBO_Vertices = 0;
	this->VBO_Normals = 0;
	this->VBO_NormalsOnVetices = 0;
	this->VAO_Mesh = 0;
	this->VAO_Normals = 0;
	this->color = glm::vec3(1.0, 1.0, 1.0);
	this->loaded = false;
	this->drawNormal = false;
}

void Mesh::loadOBJ(const char* filename)
{
	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> tempVertices;
	std::vector<glm::vec3> tempNormals;
	std::vector<glm::vec2> tempUvs;

	std::ifstream OBJFile(filename, std::ios::in);
	if (!OBJFile)
	{
		std::cout<<"ERROR : OBJ file not found"<<std::endl;
		return;
	}
	std::cout<<"OBJ file "<<filename<<" is found"<<std::endl;
	
	std::string currentLine;
	std::string header;
	while(std::getline(OBJFile, currentLine))
	{
		header.clear();
		OBJFile >> header;
		if (header.compare("v") == 0)
		{
			glm::vec3 vertex;
			OBJFile >> vertex.x >> vertex.y >> vertex.z;
			tempVertices.push_back(vertex);
		}
		else if (header.compare("vn") == 0)
		{
			glm::vec3 vertex;
			OBJFile >> vertex.x >> vertex.y >> vertex.z;
			tempNormals.push_back(vertex);
		}
		else if (header.compare("vt") == 0)
		{
			glm::vec2 vertex;
			OBJFile >> vertex.x >> vertex.y;
			tempUvs.push_back(vertex);
		}
		else if (header.compare("f") == 0)
		{
			unsigned int vertexIndex[3] = {-1}, uvIndex[3] = {-1}, normalIndex[3] = {-1};
			if (tempNormals.size() == 0 && tempUvs.size() == 0)
			{
				OBJFile >> vertexIndex[0] >> vertexIndex[1] >> vertexIndex[2];
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
			}
			else if (tempNormals.size() > 0 && tempUvs.size() == 0)
			{
				char temp;
				OBJFile >> vertexIndex[0] >> temp >> temp >> normalIndex[0] >> vertexIndex[1] >> temp >> temp >> normalIndex[1] >> vertexIndex[2] >> temp >> temp >> normalIndex[2];
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
				normalIndices.push_back(normalIndex[0]);
				normalIndices.push_back(normalIndex[1]);
				normalIndices.push_back(normalIndex[2]);
			}
			else if (tempNormals.size() == 0 && tempUvs.size() > 0)
			{
				char temp;
				OBJFile >> vertexIndex[0] >> temp >> uvIndex[0] >> vertexIndex[1] >> temp >> uvIndex[1] >> vertexIndex[2] >> temp >> uvIndex[2];
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);
			}
			else if (tempNormals.size() > 0 && tempUvs.size() > 0)
			{
				char temp;
				OBJFile >> vertexIndex[0] >> temp >> uvIndex[0] >> temp >> normalIndex[0] >> vertexIndex[1] >> temp >> uvIndex[1] >> temp >> normalIndex[1] >> vertexIndex[2] >> temp >> uvIndex[2] >> temp >> normalIndex[2];
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);
				normalIndices.push_back(normalIndex[0]);
				normalIndices.push_back(normalIndex[1]);
				normalIndices.push_back(normalIndex[2]);
			}
		}
	}

	for (unsigned int i=0; i<vertexIndices.size(); i++)
	{
		unsigned int vertexIndex = vertexIndices[i];
		this->vertices.push_back(glm::vec3(tempVertices[vertexIndex-1]));
		if (tempUvs.size() > 0)
		{
			unsigned int uvIndex = uvIndices[i];
			this->uvs.push_back(glm::vec2(tempUvs[uvIndex-1]));
		}
		if (tempNormals.size() > 0)
		{
			unsigned int normalIndex = normalIndices[i];
			this->normals.push_back(glm::vec3(tempNormals[normalIndex-1]));
		}
	}
	if (tempNormals.size() > 0)
	{
		for (unsigned int i=0; i<vertexIndices.size(); i++)
		{
			this->normalsOnVetices.push_back(this->vertices[i]);
			this->normalsOnVetices.push_back(this->vertices[i]+this->normals[i]);
		}
	}

	loadMesh();

	this->loaded = true;
}

void Mesh::loadMesh()
{
	/***********************VBO Vertices***********************/
	if (glIsBuffer(this->VBO_Vertices) == GL_TRUE)
		glDeleteBuffers(1, &this->VBO_Vertices);
	glGenBuffers(1, &this->VBO_Vertices);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Vertices);
		glBufferData(GL_ARRAY_BUFFER, this->vertices.size()*sizeof(glm::vec3), &this->vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/***********************VBO Normals***********************/
	if (glIsBuffer(this->VBO_Normals) == GL_TRUE)
		glDeleteBuffers(1, &this->VBO_Normals);
	glGenBuffers(1, &this->VBO_Normals);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Normals);
		glBufferData(GL_ARRAY_BUFFER, this->normals.size()*sizeof(glm::vec3), &this->normals[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/***********************VBO NormalsOnVetices***********************/
	if (glIsBuffer(this->VBO_NormalsOnVetices) == GL_TRUE)
		glDeleteBuffers(1, &this->VBO_NormalsOnVetices);
	glGenBuffers(1, &this->VBO_NormalsOnVetices);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_NormalsOnVetices);
		glBufferData(GL_ARRAY_BUFFER, this->normalsOnVetices.size()*sizeof(glm::vec3), &this->normalsOnVetices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/***********************VAO Mesh***********************/
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

void Mesh::draw(GLuint shaderID)
{
	glUniformMatrix4fv(glGetUniformLocation(shaderID, "Transform"), 1, GL_FALSE, &this->transform[0][0]);
	glUniform3f(glGetUniformLocation(shaderID, "ObjectColor"), this->color.x, this->color.y, this->color.z);
	glBindVertexArray(this->VAO_Mesh);
		glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
	glBindVertexArray(0);
	if (this->drawNormal)
	{
		glBindVertexArray(this->VAO_Normals);
			glDrawArrays(GL_LINES, 0, this->normalsOnVetices.size());
		glBindVertexArray(0);
	}
}

void Mesh::translate(glm::vec3 translation)
{
	this->transform[3][0] += translation[0];
	this->transform[3][1] += translation[1];
	this->transform[3][2] += translation[2];
}

void Mesh::scale(glm::vec3 scaling)
{
	this->transform[0][0] *= scaling[0];
	this->transform[1][1] *= scaling[1];
	this->transform[2][2] *= scaling[2];
}

void Mesh::rotate(float alpha, glm::vec3 axis, bool radian)
{
	if (!radian)
		alpha = 3.14159265359 * alpha / 180.0;
	glm::normalize(axis);
	float c = cos(alpha), s = sin(alpha);
	this->transform[0][0] = axis.x*axis.x + (1 - axis.x*axis.x)*c;		this->transform[1][0] = axis.x*axis.y*(1-c) - axis.z*s;				this->transform[2][0] = axis.x*axis.z*(1-c) + axis.y*s;
	this->transform[0][1] = axis.x*axis.y*(1-c) + axis.z*s;				this->transform[1][1] = axis.y*axis.y + (1 - axis.y*axis.y)*c;		this->transform[2][1] = axis.y*axis.z*(1-c) - axis.x*s;
	this->transform[0][2] = axis.x*axis.z*(1-c) - axis.y*s;				this->transform[1][2] = axis.y*axis.z*(1-c) + axis.x*s;				this->transform[2][2] = axis.z*axis.z + (1 - axis.z*axis.z)*c;
}

Mesh::~Mesh()
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