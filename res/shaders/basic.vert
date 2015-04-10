#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec2 vertexUV;

// Output data
out vec3 Position_worldspace;
out vec3 Normal_cameraspace;
out vec3 LightDirection_cameraspace;
out vec3 EyeDirection_cameraspace;
out vec2 UV;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform vec3 PosLamp01;
uniform vec3 PosCamera;
uniform vec3 ObjectPosition;
uniform vec3 ObjectScale;
uniform vec3 ObjectColor;

void main()
{
	vec4 vertex = vec4(ObjectPosition+ObjectScale*vertexPosition_modelspace,1);
	gl_Position =  Projection*View*Model * vertex;
	Position_worldspace = (Model * vertex).xyz;

	Normal_cameraspace = (View * Model * vec4(vertexNormal, 0)).xyz;

	vec3 vertexPosition_cameraspace = ( View * Model * vertex).xyz;
	EyeDirection_cameraspace = PosCamera - vertexPosition_cameraspace;

	vec3 LightPosition_cameraspace = ( View * vec4(PosLamp01,1)).xyz;
	LightDirection_cameraspace = LightPosition_cameraspace + EyeDirection_cameraspace;

	UV = vertexUV;
}

