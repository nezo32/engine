#version 460

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec3 vertex_color;
layout (location = 3) in vec3 vertex_normal;
layout (location = 2) in vec2 vertex_textureCoordinate;

out vec3 vs_position;
out vec3 vs_color;
out vec2 vs_textureCoordinate;

out vec3 normal;
out vec3 fragment_position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
//uniform float ratio;

void main() {
	vs_position = vertex_position;
	vs_color = vertex_color;
	vs_textureCoordinate = vec2(vertex_textureCoordinate.x, vertex_textureCoordinate.y * -1);

	fragment_position = vec3(model * vec4(vertex_position, 1.f));
	normal = mat3(transpose(inverse(model))) * vertex_normal;  
	gl_Position = projection * view * model * vec4(vertex_position, 1.f);
}