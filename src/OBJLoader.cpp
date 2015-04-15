#include "OBJLoader.h"

OBJLoader::OBJLoader()
{

}

void OBJLoader::loadOBJ(std::string filename, Mesh* mesh)
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

	std::vector<glm::vec3>* vertex = mesh->getVertex();
	std::vector<glm::vec3>* normals = mesh->getNormals();
	std::vector<glm::vec2>* uvs = mesh->getUvs();

	for (unsigned int i=0; i<vertexIndices.size(); i++)
	{
		unsigned int vertexIndex = vertexIndices[i];
		vertex->push_back(glm::vec3(tempVertices[vertexIndex-1]));
		if (tempUvs.size() > 0)
		{
			unsigned int uvIndex = uvIndices[i];
			uvs->push_back(glm::vec2(tempUvs[uvIndex-1]));
		}
		if (tempNormals.size() > 0)
		{
			unsigned int normalIndex = normalIndices[i];
			normals->push_back(glm::vec3(tempNormals[normalIndex-1]));
		}
	}

	mesh->setDrawingMode(GL_TRIANGLES);
}

OBJLoader::~OBJLoader()
{

}
