#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;

// Output data
out vec3 Normal_cameraspace;
out vec3 LightDirection_cameraspace;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

void main()
{
	gl_Position =  Projection*View*Model * vec4(vertexPosition_modelspace,1);
	vec3 vertexPosition_cameraspace = ( View * Model * vec4(vertexPosition_modelspace,1)).xyz;

	Normal_cameraspace = (View * Model * vec4(vertexNormal, 0)).xyz;

	vec3 EyeDirection_cameraspace = vec3(0,0,0) - vertexPosition_cameraspace;

	vec3 LightPosition_cameraspace = ( View * vec4(vec3(4.0, 1.0, 4.0),1)).xyz;
	LightDirection_cameraspace = LightPosition_cameraspace + EyeDirection_cameraspace;
}

