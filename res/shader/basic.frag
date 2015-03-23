#version 330 core

// Input data
in vec3 Normal_cameraspace;
in vec3 LightDirection_cameraspace;
in vec3 EyeDirection_cameraspace;

// Ouput data
out vec3 color;

void main()
{
	vec3 N = normalize(Normal_cameraspace);
	vec3 L = normalize(LightDirection_cameraspace);
	vec3 E = normalize(EyeDirection_cameraspace);
	vec3 R = reflect(-L, N);
	float i_a = 0.1;
	float i_d = clamp(dot(L, N), 0, 1);
	float i_s = pow(clamp(dot(E, R), 0, 1), 5);
	float I = i_a + i_d + i_s;
	color = vec3(1.0, 0.0, 0.0) * vec3(1.0, 1.0, 1.0) * I;
}