#version 330 core

uniform vec3 posParticle;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

void main()
{
	gl_Position =  Projection*View*Model *vec4(posParticle,1);
}

