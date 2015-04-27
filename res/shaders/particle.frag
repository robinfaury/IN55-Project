#version 330 core

in vec3 vertexPositionMV;

out vec3 color;

uniform vec3 PosCamera;

void main()
{
	color = vec3(1.0, 1.0, 1.0);
}
