#include "Camera.h"

Camera::Camera() {
	position = glm::vec3(0.f);
	direction = glm::vec3(0.f);
	front = glm::vec3(0.f, 0.f, -1.f);
}

Camera::~Camera() {}

void Camera::ChangeDirection(float yaw, float pitch) {
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch)) * -1;
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(direction);
}

void Camera::Use(GLint program) {
	glm::mat4 view = glm::lookAt(position, position + front, worldUp);
	setUniformM4(program, "view", glm::value_ptr(view));
}