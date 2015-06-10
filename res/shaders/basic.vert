#version 330 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform mat4 NormalMatrix;

uniform vec3 ObjectScale;

out vec2 texCoord;
smooth out vec3 vNormal;
smooth out vec3 vWorldPos;

void main()
{
	vWorldPos = (Model * vec4(vertex*ObjectScale, 1.0)).xyz;
	gl_Position = Projection * View * vec4(vWorldPos, 1.0);
	texCoord = uv;
	vNormal = (NormalMatrix * vec4(normal, 0.0)).xyz;
}

