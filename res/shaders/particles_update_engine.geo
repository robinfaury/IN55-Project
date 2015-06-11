#version 330 

layout(points) in; 
layout(points) out; 
layout(max_vertices = 81) out; 

in vec3 vertexPass[]; 
in vec3 velocityPass[]; 
in vec3 colorPass[]; 
in float lifePass[]; 
in float sizePass[]; 
in int typePass[]; 

out vec3 vertex; 
out vec3 velocity;
out vec3 color; 
out float life; 
out float size; 
out int type; 

uniform vec3 source;
uniform vec3 gravity;
uniform vec3 minimumVelocity, rangeVelocity;

uniform vec3 initColor;
uniform float initSize;  

uniform float minimumLife, rangeLife;
uniform float timePassed;

uniform vec3 randomSeed;
vec3 localSeed; 

uniform int numberNewParticles;
uniform int first;

// This function returns random number from zero to one
float randZeroOne() 
{ 
    uint n = floatBitsToUint(localSeed.y * 214013.0 + localSeed.x * 2531011.0 + localSeed.z * 141251.0); 
    n = n * (n * n * 15731u + 789221u); 
    n = (n >> 9u) | 0x3F800000u; 
  
    float fRes =  2.0 - uintBitsToFloat(n); 
    localSeed = vec3(localSeed.x + 147158.0 * fRes, localSeed.y*fRes  + 415161.0 * fRes, localSeed.z + 324154.0*fRes); 
    return fRes; 
} 

void main() 
{
	localSeed = randomSeed;
	vertex = vertexPass[0];
	velocity = velocityPass[0]; 

	color = colorPass[0]; 
	life = lifePass[0]-timePassed; 
	size = sizePass[0]; 
	type = typePass[0];
	
	if (typePass[0] == 0)
	{
		EmitVertex(); 
		EndPrimitive();
		
		if (first == 1)
		{
			for (int i=0; i<2; ++i)
			{
				for (int j=0; j<2; ++j)
				{
					vertex = vertexPass[0] + vec3(0.1*i, 0.01*randZeroOne(), 0.1*j);
					EmitVertex();
					EndPrimitive();
				}
			}
		}
		else
		{
			for (int i=0; i<numberNewParticles; ++i)
			{
				type = 1;
				velocity = minimumVelocity + vec3(rangeVelocity.x*randZeroOne(), rangeVelocity.y*randZeroOne(), rangeVelocity.z*randZeroOne());
				color = colorPass[0];
				life = minimumLife + rangeLife*randZeroOne();
				EmitVertex();
				EndPrimitive();
			}
		}
	}
	else if (life > 0.0)
	{
		vertex = vertexPass[0] + velocity;
		velocity = velocityPass[0] + gravity;
		EmitVertex(); 
		EndPrimitive();
	}
}