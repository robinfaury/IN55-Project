#version 330 core

// Input data
in vec3 fragmentColor;

// Ouput data
out vec3 color;

void main()
{
	color = fragmentColor;
}