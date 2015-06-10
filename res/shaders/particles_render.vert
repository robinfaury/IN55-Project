#version 330

layout (location = 0) in vec3 vertex;
layout (location = 2) in vec3 color;
layout (location = 3) in float life;
layout (location = 4) in float size;
layout (location = 5) in int type;

out vec3 colorPass;
out float lifePass;
out float sizePass;
out int typePass;


uniform struct Matrices
{
	mat4 mProj;
	mat4 mView;
} matrices;

void main()
{
   gl_Position = vec4(vertex, 1.0);
   colorPass = color;
   sizePass = size;
   lifePass = life;
   typePass = type;
}