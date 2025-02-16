#ifndef HEADERS_ENTITIES_CAMERA_H_
#define HEADERS_ENTITIES_CAMERA_H_

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "uniform.h"

class Camera {
public:
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 front;
	glm::vec3 worldUp{ 0.f, 1.f, 0.f };
	float speed = 2.5f;

	Camera();
	~Camera();

	void ChangeDirection(float yaw, float pitch);
	void Use(GLint program);
};

#endif // !HEADERS_ENTITIES_CAMERA_H_