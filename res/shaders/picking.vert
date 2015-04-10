#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform vec3 ObjectPosition;
uniform vec3 ObjectScale;

void main()
{
	gl_Position = Projection*View*Model * vec4(ObjectPosition+vertexPosition_modelspace,1);
}

