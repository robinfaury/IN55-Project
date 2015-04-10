#ifndef _SHADER_H
#define _SHADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <GL/glew.h>

class Shader
{
private:
	GLuint vertexShaderID;
	GLuint fragmentShaderID;
	GLuint programID;

	std::string vertexSource;
	std::string fragmentSource;

	bool loaded;
public:
	Shader();
	Shader(std::string vertexSource, std::string fragmentSource);
	Shader(Shader const &shader);

	bool load();
	bool buildShader(GLuint &shaderID, GLenum type, std::string const &filename);

	Shader& operator= (Shader const &shader);

	GLuint getProgramID() const {return this->programID;}

	bool isLoaded() {return this->loaded;}

	~Shader();
};

#endif 