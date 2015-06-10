#version 330

uniform struct Matrices
{
	mat4 mProj;
	mat4 mView;
} matrices;

uniform vec3 vQuad1, vQuad2;

layout(points) in;
layout(triangle_strip) out;
layout(max_vertices = 4) out;

in vec3 colorPass[];
in float lifePass[];
in float sizePass[];
in int typePass[];

smooth out vec2 texCoord;
flat out vec4 colorPart;

void main()
{
	if (typePass[0] != 0)
	{
		vec3 initVertex = gl_in[0].gl_Position.xyz;
		float fSize = sizePass[0];
		mat4 mVP = matrices.mProj*matrices.mView;

		colorPart = vec4(colorPass[0], lifePass[0]);

		vec3 vPos = initVertex+(-vQuad1-vQuad2)*fSize;
		texCoord = vec2(0.0, 0.0);
		gl_Position = mVP*vec4(vPos, 1.0);
		EmitVertex();

		vPos = initVertex+(-vQuad1+vQuad2)*fSize;
		texCoord = vec2(0.0, 1.0);
		gl_Position = mVP*vec4(vPos, 1.0);
		EmitVertex();

		vPos = initVertex+(vQuad1-vQuad2)*fSize;
		texCoord = vec2(1.0, 0.0);
		gl_Position = mVP*vec4(vPos, 1.0);
		EmitVertex();

		vPos = initVertex+(vQuad1+vQuad2)*fSize;
		texCoord = vec2(1.0, 1.0);
		gl_Position = mVP*vec4(vPos, 1.0);
		EmitVertex();

		EndPrimitive();
	}
}