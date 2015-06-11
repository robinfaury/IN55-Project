#version 330

uniform sampler2D gSampler;
uniform int maximumLife;

smooth in vec2 texCoord;
flat in vec4 colorPart;

out vec4 FragColor;

void main()
{
	vec4 texColor = texture2D(gSampler, texCoord);
	float alpha = distance(texColor.xyz, vec3(0.0, 0.0, 0.0));
	FragColor = vec4(texColor.xyz, alpha);
}