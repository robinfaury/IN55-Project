#version 330 core

// Ouput data
out vec3 color;

uniform vec3 ObjectColorID;

void main()
{
	color = ObjectColorID;
}
