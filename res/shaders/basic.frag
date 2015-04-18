#version 330 core

// Input data
in vec3 Position_worldspace;
in vec3 Normal_cameraspace;
in vec3 LightDirection_cameraspace;
in vec3 EyeDirection_cameraspace;
in vec2 UV;

// Ouput data
out vec3 color;

uniform vec3 PosLamp01;
uniform vec3 ObjectColor;
uniform int isNormals;
uniform int isTexture;
uniform sampler2D Tex01;

void main()
{
	vec3 LightColor = vec3(1,1,1);
	float LightPower = 30.0f;

	vec3 MaterialDiffuseColor;
	if (isTexture == 1)
		MaterialDiffuseColor = texture(Tex01, UV).rgb;
	else
		MaterialDiffuseColor = vec3(1.0, 0.0, 0.0);
	vec3 MaterialAmbientColor = vec3(0.1,0.1,0.1) * MaterialDiffuseColor;
	vec3 MaterialSpecularColor = vec3(0.3,0.3,0.3);

	float distance = length(PosLamp01 - Position_worldspace );

	vec3 N = normalize(Normal_cameraspace);
	vec3 L = normalize(LightDirection_cameraspace);
	vec3 E = normalize(EyeDirection_cameraspace);
	vec3 R = reflect(-L, N);
	vec3 i_a = MaterialAmbientColor;
	vec3 i_d = MaterialDiffuseColor * LightColor * LightPower * clamp(dot(L, N), 0, 1) / (distance*distance);
	vec3 i_s = MaterialSpecularColor * LightColor * LightPower * pow(clamp(dot(E, R), 0, 1), 500) / (distance*distance);
	color = i_a + i_d + i_s;
}
