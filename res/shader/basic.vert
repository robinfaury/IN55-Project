#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;

// Output data
out vec3 fragmentColor;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

void main()
{
	gl_Position =  Projection*View*Model * vec4(vertexPosition_modelspace,1);
	vec3 positionWord = (Model * vec4(vertexPosition_modelspace, 1)).xyz;

	float cosTheta = clamp(dot(vertexNormal, vec3(4.0, 4.0, 4.0)), 0, 1);

	fragmentColor = vec3(1.0, 1.0, 1.0);
}

