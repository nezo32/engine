#version 460

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec3 vertex_color;
layout (location = 2) in vec2 vertex_textureCoordinate;

out vec3 vs_position;
out vec3 vs_color;
out vec2 vs_textureCoordinate;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
//uniform float ratio;

void main() {
	//vec3 ratio_position = vec3(vertex_position.x / ratio, vertex_position.yz);

	vs_position = vertex_position;
	vs_color = vertex_color;
	vs_textureCoordinate = vec2(vertex_textureCoordinate.x, vertex_textureCoordinate.y * -1);

	gl_Position = projection * view * model * vec4(vertex_position, 1.f);
}