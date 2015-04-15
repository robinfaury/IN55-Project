#include "Shader.h"

Shader::Shader()
{
	this->vertexShaderID = 0;
	this->fragmentShaderID = 0;
	this->programID = 0;
	this->loaded = false;
}

Shader::Shader(std::string vertexSource, std::string fragmentSource)
{
	this->vertexShaderID = 0;
	this->fragmentShaderID = 0;
	this->programID = 0;
	this->loaded = false;
	this->vertexSource = vertexSource;
	this->fragmentSource = fragmentSource;
	load();
}

Shader::Shader(Shader const &shader)
{
	this->vertexSource = shader.vertexSource;
	this->fragmentSource = shader.fragmentSource;
	this->loaded = false;
	load();
}

bool Shader::load()
{
	if (glIsShader(this->vertexShaderID) == GL_TRUE)
		glDeleteShader(this->vertexShaderID);
	if (glIsShader(this->fragmentShaderID) == GL_TRUE)
		glDeleteShader(this->fragmentShaderID);
	if (glIsProgram(this->programID) == GL_TRUE)
		glDeleteProgram(this->programID);

	if (!buildShader(this->vertexShaderID, GL_VERTEX_SHADER, this->vertexSource))
		return false;
	if (!buildShader(this->fragmentShaderID, GL_FRAGMENT_SHADER, this->fragmentSource))
		return false;

	this->programID = glCreateProgram();
	glAttachShader(this->programID, this->vertexShaderID);
	glAttachShader(this->programID, this->fragmentShaderID);

	glBindAttribLocation(this->programID, 0, "in_Vertex");
	glBindAttribLocation(this->programID, 1, "in_Color");
	glBindAttribLocation(this->programID, 2, "in_TexCoord0");

	glLinkProgram(this->programID);

	GLint linkError =0;
	glGetProgramiv(this->programID, GL_LINK_STATUS, &linkError);
	if (linkError != GL_TRUE)
	{
		GLint size = 0;
		glGetProgramiv(this->programID, GL_INFO_LOG_LENGTH, &size);

		char* error = new char[size+1];
		glGetProgramInfoLog(this->programID, size, &size, error);
		error[size] = '\0';
		std::cout<<error<<std::endl;
		delete[] error;
		
		glDeleteProgram(this->programID);

		return false;
	}
	
	std::cout<<"Shader "<<this->vertexSource<<" has compiled with success"<<std::endl;
	this->loaded = true;
	return true;
}

bool Shader::buildShader(GLuint &shaderID, GLenum type, std::string const &filename)
{
	shaderID = glCreateShader(type);
	if (!shaderID)
	{
		std::cout<<"ERROR : Fail to create the " <<type<< " shader."<<std::endl;
		return false;
	}

	std::fstream file(filename.c_str());
	if (!file)
	{
		std::cout<<"ERROR : File " <<filename<< "not found."<<std::endl;
		glDeleteShader(shaderID);
		return false;
	}

	std::string line;
	std::string sourceCode;
	while (getline(file, line))
		sourceCode += line + '\n';
	file.close();

	const GLchar* sourceCodeC_str = sourceCode.c_str();
	glShaderSource(shaderID, 1, &sourceCodeC_str, 0);
	glCompileShader(shaderID);

	GLint buildError = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &buildError);
	if (buildError != GL_TRUE)
	{
		GLint size = 0;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &size);

		char* error = new char[size+1];
		glGetShaderInfoLog(shaderID, size, &size, error);
		error[size] = '\0';
		std::cout<<error<<std::endl;
		delete[] error;
		
		glDeleteShader(shaderID);

		return false;
	}
	else
		return true;
}

Shader& Shader::operator= (Shader const &shader)
{
	this->vertexSource = shader.vertexSource;
	this->fragmentSource = shader.fragmentSource;
	load();

	return *this;
}

Shader::~Shader()
{
	glDeleteShader(this->vertexShaderID);
	glDeleteShader(this->fragmentShaderID);
	glDeleteProgram(this->programID);
}