#version 330 core

layout (points) in;
layout(triangle_strip, max_vertices=4) out;
out vec2 TexCoord;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform vec3 PosCamera;

void main()
{
	mat4 MV = View*Model;
	if (gl_in[0].gl_Position.x == 0.0 && gl_in[0].gl_Position.y == 0.0 && gl_in[0].gl_Position.z == 0.0)
	{
		gl_Position = Projection*MV*gl_in[0].gl_Position;
		EmitVertex();
		EndPrimitive();
	}
	else
	{
		gl_Position = Projection*MV*gl_in[0].gl_Position;
		TexCoord = vec2(0.0, 0.0);
		EmitVertex();

		gl_Position = Projection*(MV*gl_in[0].gl_Position - vec4(0, 0.05, 0, 0));
		TexCoord = vec2(0.0, 1.0);
		EmitVertex();

		gl_Position = Projection*(MV*gl_in[0].gl_Position - vec4(0.05, 0, 0, 0));
		TexCoord = vec2(1.0, 0.0);
		EmitVertex();

		gl_Position = Projection*(MV*gl_in[0].gl_Position - vec4(0.05, 0.05, 0, 0));
		TexCoord = vec2(1.0, 1.0);
		EmitVertex();
		EndPrimitive();
	}
}

