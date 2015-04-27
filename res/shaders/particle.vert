#version 330 core

// Input data
layout(location = 0) in vec3 vertexPosition_modelspace;

// Ouput data
out vec3 color;
out vec3 vertexPositionMV;


uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform vec3 PosCamera;

void main()
{
	gl_Position =  Projection*View*Model *vec4(vertexPosition_modelspace,1);
	gl_PointSize = 100/(gl_Position.w*10);
}

