#version 330 core

// Input data
in vec3 Normal_cameraspace;
in vec3 LightDirection_cameraspace;

// Ouput data
out vec3 color;

void main()
{
	float I = clamp(dot(normalize(Normal_cameraspace), normalize(LightDirection_cameraspace)), 0, 1);
	color = vec3(1.0, 0.0, 0.0) * I;
}