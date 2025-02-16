#ifndef HEADERS_GLOBAL_VERTEX_H_
#define HEADERS_GLOBAL_VERTEX_H_

#include "glm.hpp"

struct Vertex {
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 textureCoordinate;
	glm::vec3 normal;
};

#endif // !HEADERS_GLOBAL_VERTEX_H_


