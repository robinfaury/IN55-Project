#include "Mesh.h"


Mesh::Mesh() : Object3D()
{
	this->loaded = false;
}

Mesh::Mesh(const char* filename, int drawingMode) : Object3D()
{
	this->loaded = false;
	this->drawingMode = drawingMode;

	loadOBJ(filename);

	computeNormalOnVertex();

	loadVBO();
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

	this->loaded = true;
}

Mesh::~Mesh()
{
	
}