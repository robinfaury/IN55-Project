#version 330 

layout (location = 0) in vec3 vertex; 
layout (location = 1) in vec3 velocity; 
layout (location = 2) in vec3 color; 
layout (location = 3) in float life; 
layout (location = 4) in float size; 
layout (location = 5) in int type; 

out vec3 vertexPass; 
out vec3 velocityPass; 
out vec3 colorPass; 
out float lifePass; 
out float sizePass; 
out int typePass; 

void main() 
{ 
  vertexPass = vertex; 
  velocityPass = velocity; 
  colorPass = color; 
  lifePass = life; 
  sizePass = size; 
  typePass = type; 
}