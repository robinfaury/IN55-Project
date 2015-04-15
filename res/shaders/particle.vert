#version 330 core

// Input data
layout(location = 0) in vec3 vertexPosition_modelspace;

// Ouput data
out vec3 color;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

void main()
{
	gl_Position =  Projection*View*Model *vec4(vertexPosition_modelspace,1);
}

