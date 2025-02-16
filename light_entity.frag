#version 460

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_textureCoordinate;

out vec4 fs_color;

uniform vec3 light_color;

void main() {
	float ambient_strength = 0.1f;
	vec3 ambient = light_color * ambient_strength;

	fs_color = vec4(light_color, 1.f);
}