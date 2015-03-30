#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform mat4 Transform;

void main()
{
	gl_Position =  Projection*View*Model * Transform*vec4(vertexPosition_modelspace,1);
}

