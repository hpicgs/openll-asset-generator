#version 140
#extension GL_ARB_explicit_attrib_location : require

layout (location = 0) in vec2 corner;

uniform mat4 transform3D;

out vec4 color;
out vec2 v_uv;

void main()
{
    gl_Position = transform3D * vec4(corner * 2.0 - 1.0, 0.0, 1.0);
    color = vec4(corner, 0.0, 1.0);
	v_uv = corner;
}