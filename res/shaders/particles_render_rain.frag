#version 330

uniform sampler2D gSampler;

smooth in vec2 texCoord;
flat in vec4 colorPart;

out vec4 FragColor;

void main()
{
	float dist = length(vec2(0.5, 0.5) - texCoord)*2;
	FragColor = vec4(colorPart.xyz, 1-dist);
}