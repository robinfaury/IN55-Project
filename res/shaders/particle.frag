#version 330 core

in vec2 TexCoord;

out vec4 color;

uniform vec3 particleColor;
uniform int isTexture;
uniform sampler2D Tex01;

void main()
{
	float dist = length(vec2(0.5, 0.5) - TexCoord)*2;
	if (isTexture == 1)
		color = vec4(texture(Tex01, TexCoord).rgb, 1.0);
	else
		color = vec4(1.0 - particleColor*dist, 0.5);
	if (color.r < 0.1 && color.g < 0.1 && color.b < 0.1)
		discard;
}
