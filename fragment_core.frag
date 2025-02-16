#version 460

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_textureCoordinate;

in vec3 fragment_position;
in vec3 normal;

out vec4 fs_color;

uniform vec3 light_pos;
uniform vec3 light_color;
uniform vec3 cam_pos;

void main() {
	float ambient_strength = 0.1f;
	vec3 ambient = light_color * ambient_strength;

	vec3 norm = normalize(normal);
	vec3 light_direction = normalize(light_pos - fragment_position);
	float diff = max(dot(norm, light_direction), 0.f);
	vec3 diffuse = diff * light_color;

	float specular_strength = 0.5;
    vec3 view_direction = normalize(cam_pos - fragment_position);
    vec3 reflect_direction = reflect(-light_direction, norm);  
    float spec = pow(max(dot(view_direction, reflect_direction), 0.0), 64);
    vec3 specular = specular_strength * spec * light_color;  

	fs_color = vec4(vs_color * (ambient + diffuse + specular), 1.f);
}