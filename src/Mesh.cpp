#include "Mesh.h"

Mesh::Mesh()
{
	this->vertexBufferID = 0;
	this->normalBufferID = 0;
	this->VAOID = 0;
	this->color = glm::vec3(1.0, 0.0, 1.0);
	this->loaded = false;
}

Mesh::Mesh(const char* filename)
{
	this->vertexBufferID = 0;
	this->normalBufferID = 0;
	this->VAOID = 0;
	this->color = glm::vec3(1.0, 0.0, 1.0);
	this->loaded = false;
	loadOBJ(filename);
}

Mesh::Mesh(const char* filename, Shader* shader)
{
	this->vertexBufferID = 0;
	this->normalBufferID = 0;
	this->VAOID = 0;
	this->color = glm::vec3(1.0, 0.0, 1.0);
	this->loaded = false;
	this->shader = shader;
	loadOBJ(filename);
}


void Mesh::loadMesh()
{
	/***********************Vertex Buffer***********************/
	if (glIsBuffer(this->vertexBufferID) == GL_TRUE)
		glDeleteBuffers(1, &this->vertexBufferID);
	glGenBuffers(1, &this->vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, this->vertices.size()*sizeof(glm::vec3), &this->vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/***********************normal Buffer***********************/
	if (!this->normals.empty())
	{
		if (glIsBuffer(this->normalBufferID) == GL_TRUE)
			glDeleteBuffers(1, &this->normalBufferID);
		glGenBuffers(1, &this->normalBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, this->normalBufferID);
			glBufferData(GL_ARRAY_BUFFER, this->normals.size()*sizeof(glm::vec3), &this->normals[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	/***********************VAO***********************/
	if (glIsVertexArray(this->VAOID == GL_TRUE))
		glDeleteVertexArrays(1, &this->VAOID);
	glGenVertexArrays(1, &this->VAOID);
	glBindVertexArray(this->VAOID);
		glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferID);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
			glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ARRAY_BUFFER, this->normalBufferID);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
			glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
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
		else
			this->normals.push_back(glm::vec3(1.0, 0.0, 1.0));
		if (tempNormals.size() > 0)
		{
			unsigned int normalIndex = normalIndices[i];
			this->normals.push_back(glm::vec3(tempNormals[normalIndex-1]));
		}
	}

	loadMesh();

	this->loaded = true;
}

void Mesh::draw(glm::mat4 &model, glm::mat4 &view, glm::mat4 &projection)
{
	glUseProgram(this->shader->getProgramID());
		glBindVertexArray(this->VAOID);
			glUniformMatrix4fv(glGetUniformLocation(this->shader->getProgramID(), "Model"), 1, GL_FALSE, &model[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(this->shader->getProgramID(), "View"), 1, GL_FALSE, &view[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(this->shader->getProgramID(), "Projection"), 1, GL_FALSE, &projection[0][0]);
			glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
		glBindVertexArray(0);
	glUseProgram(0);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &this->vertexBufferID);
	glDeleteBuffers(1, &this->normalBufferID);
	glDeleteVertexArrays(1, &this->VAOID);
	this->vertices.clear();
	this->normals.clear();
	this->normals.clear();
	this->uvs.clear();
}