#ifndef HEADERS_PRIMITIVES_QUAD_H_
#define HEADERS_PRIMITIVES_QUAD_H_

#include "Primitive.h"

class Quad : public Primitive {
public:
	Quad(glm::vec3 color = glm::vec3(0.5f, 0.5f, 0.5f)) : Primitive() {
		preferableDrawType = DRAW_TYPE_ELEMENT;

		Vertex v[] = {
			// POSITION							// COLOR		// TEXTURE POSITION		
			glm::vec3(0.5f, 0.5f, 0.f),			color,			glm::vec2(1.0f, 1.0f),			glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.f),		color,			glm::vec2(1.0f, 0.0f),			glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, 0.5f, 0.f),		color,			glm::vec2(0.0f, 1.0f),			glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.f),		color,			glm::vec2(0.0f, 0.0f),			glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(0.5f, 0.5f, 0.f),			color,			glm::vec2(1.0f, 1.0f),			glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.5f, -0.5f, 0.f),		color,			glm::vec2(1.0f, 0.0f),			glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, 0.5f, 0.f),		color,			glm::vec2(0.0f, 1.0f),			glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, -0.5f, 0.f),		color,			glm::vec2(0.0f, 0.0f),			glm::vec3(0.f, 0.f, -1.f),
		};

		GLuint i[] = {
			3, 1, 2,
			0, 2, 1,

			4, 5, 6,
			5, 7, 6
		};

		setInitial(v, i, sizeof(v) / sizeof(Vertex), sizeof(i) / sizeof(GLuint));
	}
};

#endif // !HEADERS_PRIMITIVES_QUAD_H_