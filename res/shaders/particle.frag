#version 330 core

in vec3 vertexPositionMV;

out vec4 color;

uniform vec3 PosCamera;

void main()
{
	vec2 p = gl_FragCoord.xy;
	color = vec4(p.x/1600, p.y/900, 1.0, 1.0);
}
