#include "Mesh.h"

Mesh::Mesh()
{
	this->VBO_Vertices = 0;
	this->VBO_Normals = 0;
	this->VBO_NormalsOnVetices = 0;
	this->VAO_Mesh = 0;
	this->VAO_Normals = 0;
	this->color = glm::vec3(1.0, 0.0, 1.0);
	this->loaded = false;
	this->drawNormal = false;
}

Mesh::Mesh(const char* filename)
{
	this->VBO_Vertices = 0;
	this->VBO_Normals = 0;
	this->VBO_NormalsOnVetices = 0;
	this->VAO_Mesh = 0;
	this->VAO_Normals = 0;
	this->color = glm::vec3(1.0, 0.0, 1.0);
	this->loaded = false;
	this->drawNormal = false;
	loadOBJ(filename);
}

Mesh::Mesh(const char* filename, Shader* shader)
{
	this->VBO_Vertices = 0;
	this->VBO_Normals = 0;
	this->VBO_NormalsOnVetices = 0;
	this->VAO_Mesh = 0;
	this->VAO_Normals = 0;
	this->color = glm::vec3(1.0, 0.0, 1.0);
	this->loaded = false;
	this->drawNormal = false;
	this->shader = shader;
	loadOBJ(filename);
}

void Mesh::loadOBJ(const char* filename)
{
	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> tempVertices;
	std::vector<glm::vec3> tempNormals;
	std::vector<glm::vec2> tempUvs;

	FILE* OBJFile = fopen(filename, "r");
	if (filename == NULL)
	{
		std::cout<<"ERROR : OBJ file not found"<<std::endl;
		return;
	}
	std::cout<<"OBJ file "<<filename<<" is found"<<std::endl;
	
	int offset = 0;
	while(offset != EOF)
	{
		char header[128];
		offset = fscanf(OBJFile, "%s", header);
		if (offset == EOF)
			break;
		if (strcmp(header, "v") == 0)
		{
			glm::vec3 vertex;
			fscanf(OBJFile, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			tempVertices.push_back(vertex);
		}
		else if (strcmp(header, "vn") == 0)
		{
			glm::vec3 normal;
			fscanf(OBJFile, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			tempNormals.push_back(normal);
		}
		else if (strcmp(header, "vt") == 0)
		{
			glm::vec2 uv;
			fscanf(OBJFile, "%f %f\n", &uv.x, &uv.y);
			tempUvs.push_back(uv);
		}
		else if (strcmp(header, "f") == 0)
		{
			unsigned int vertexIndex[3] = {-1}, uvIndex[3] = {-1}, normalIndex[3] = {-1};
			if (tempNormals.size() == 0 && tempUvs.size() == 0)
			{
				fscanf(OBJFile, "%d %d %d", &vertexIndex[0], &vertexIndex[1], &vertexIndex[2]);
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
			}
			else if (tempNormals.size() > 0 && tempUvs.size() == 0)
			{
				fscanf(OBJFile, "%d//%d %d//%d %d//%d", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
				normalIndices.push_back(normalIndex[0]);
				normalIndices.push_back(normalIndex[1]);
				normalIndices.push_back(normalIndex[2]);
			}
			else if (tempNormals.size() == 0 && tempUvs.size() > 0)
			{
				fscanf(OBJFile, "%d/%d %d/%d %d/%d", &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2]);
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);
			}
			else if (tempNormals.size() > 0 && tempUvs.size() > 0)
			{
				fscanf(OBJFile, "%d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
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

void Mesh::draw(glm::mat4 &model, glm::mat4 &view, glm::mat4 &projection)
{
	glUseProgram(this->shader->getProgramID());
		glBindVertexArray(this->VAO_Mesh);
			glUniformMatrix4fv(glGetUniformLocation(this->shader->getProgramID(), "Model"), 1, GL_FALSE, &model[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(this->shader->getProgramID(), "View"), 1, GL_FALSE, &view[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(this->shader->getProgramID(), "Projection"), 1, GL_FALSE, &projection[0][0]);
			glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
		glBindVertexArray(0);
		glBindVertexArray(this->VAO_Normals);
			glUniformMatrix4fv(glGetUniformLocation(this->shader->getProgramID(), "Model"), 1, GL_FALSE, &model[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(this->shader->getProgramID(), "View"), 1, GL_FALSE, &view[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(this->shader->getProgramID(), "Projection"), 1, GL_FALSE, &projection[0][0]);
			glDrawArrays(GL_LINES, 0, this->normalsOnVetices.size());
		glBindVertexArray(0);
	glUseProgram(0);
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