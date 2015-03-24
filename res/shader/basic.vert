#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;

// Output data
out vec3 Position_worldspace;
out vec3 Normal_cameraspace;
out vec3 LightDirection_cameraspace;
out vec3 EyeDirection_cameraspace;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform vec3 PosLamp01;
uniform vec3 PosCamera;
uniform mat4 Transform;

void main()
{
	gl_Position =  Projection*View*Model * Transform*vec4(vertexPosition_modelspace,1);
	Position_worldspace = (Model * vec4(vertexPosition_modelspace,1)).xyz;

	Normal_cameraspace = (View * Model * vec4(vertexNormal, 0)).xyz;

	vec3 vertexPosition_cameraspace = ( View * Model * vec4(vertexPosition_modelspace,1)).xyz;
	EyeDirection_cameraspace = PosCamera - vertexPosition_cameraspace;

	vec3 LightPosition_cameraspace = ( View * vec4(PosLamp01,1)).xyz;
	LightDirection_cameraspace = LightPosition_cameraspace + EyeDirection_cameraspace;
}

