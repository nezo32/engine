#ifndef HEADERS_PRIMITIVES_CUBE_H_
#define HEADERS_PRIMITIVES_CUBE_H_

#include "Primitive.h"

class Cube : public Primitive {
public:
	Cube(glm::vec3 color  = glm::vec3(0.5f, 0.5f, 0.5f)) : Primitive() {
		preferableDrawType = DRAW_TYPE_ARRAY;

		Vertex v[] = {
			// POSITION							// COLOR			// TEXTURE POSITION
			
			// FRONT
			glm::vec3(0.5f, -0.5f,  0.5f),		color,				glm::vec2(1.0f, 0.0f), // BOTTOM	RIGHT	FRONT
			glm::vec3(0.5f,  0.5f,  0.5f),		color,				glm::vec2(1.0f, 1.0f), // TOP		RIGHT	FRONT
			glm::vec3(-0.5f, -0.5f,  0.5f),		color,				glm::vec2(0.0f, 0.0f), // BOTTOM	LEFT	FRONT
			glm::vec3(0.5f,  0.5f,  0.5f),		color,				glm::vec2(1.0f, 1.0f), // TOP		RIGHT	FRONT
			glm::vec3(-0.5f,  0.5f,  0.5f),		color,				glm::vec2(0.0f, 1.0f), // TOP		LEFT	FRONT 
			glm::vec3(-0.5f, -0.5f,  0.5f),		color,				glm::vec2(0.0f, 0.0f), // BOTTOM	LEFT	FRONT

			// BACK
			glm::vec3(0.5f,  0.5f,  -0.5f),		color,				glm::vec2(1.0f, 1.0f), // TOP		RIGHT	BACK
			glm::vec3(0.5f, -0.5f,  -0.5f),		color,				glm::vec2(1.0f, 0.0f), // BOTTOM	RIGHT	BACK
			glm::vec3(-0.5f, -0.5f,  -0.5f),	color,				glm::vec2(0.0f, 0.0f), // BOTTOM	LEFT	BACK
			glm::vec3(-0.5f,  0.5f,  -0.5f),	color,				glm::vec2(0.0f, 1.0f), // TOP		LEFT	BACK 
			glm::vec3(0.5f,  0.5f,  -0.5f),		color,				glm::vec2(1.0f, 1.0f), // TOP		RIGHT	BACK
			glm::vec3(-0.5f, -0.5f,  -0.5f),	color,				glm::vec2(0.0f, 0.0f), // BOTTOM	LEFT	BACK

			// UP
			glm::vec3(-0.5f,  0.5f,  0.5f),		color,				glm::vec2(0.0f, 1.0f), // TOP		LEFT	FRONT 
			glm::vec3(0.5f,  0.5f,  0.5f),		color,				glm::vec2(1.0f, 1.0f), // TOP		RIGHT	FRONT
			glm::vec3(0.5f,  0.5f,  -0.5f),		color,				glm::vec2(1.0f, 0.0f), // TOP		RIGHT	BACK
			glm::vec3(-0.5f,  0.5f,  0.5f),		color,				glm::vec2(0.0f, 1.0f), // TOP		LEFT	FRONT 
			glm::vec3(0.5f,  0.5f,  -0.5f),		color,				glm::vec2(1.0f, 0.0f), // TOP		RIGHT	BACK
			glm::vec3(-0.5f,  0.5f,  -0.5f),	color,				glm::vec2(0.0f, 0.0f), // TOP		LEFT	BACK 

			// BOTTOM
			glm::vec3(0.5f,  -0.5f,  0.5f),		color,				glm::vec2(1.0f, 1.0f), // BOTTOM	RIGHT	FRONT
			glm::vec3(-0.5f,  -0.5f,  0.5f),	color,				glm::vec2(0.0f, 1.0f), // BOTTOM	LEFT	FRONT 
			glm::vec3(0.5f,  -0.5f,  -0.5f),	color,				glm::vec2(1.0f, 0.0f), // BOTTOM	RIGHT	BACK
			glm::vec3(0.5f,  -0.5f,  -0.5f),	color,				glm::vec2(1.0f, 0.0f), // BOTTOM	RIGHT	BACK
			glm::vec3(-0.5f,  -0.5f,  0.5f),	color,				glm::vec2(0.0f, 1.0f), // BOTTOM	LEFT	FRONT 
			glm::vec3(-0.5f,  -0.5f,  -0.5f),	color,				glm::vec2(0.0f, 0.0f), // BOTTOM	LEFT	BACK

			// LEFT
			glm::vec3(-0.5f,  0.5f,  0.5f),		color,				glm::vec2(1.0f, 1.0f), // TOP		LEFT	FRONT
			glm::vec3(-0.5f,  0.5f,  -0.5f),	color,				glm::vec2(0.0f, 1.0f), // TOP		LEFT	BACK 
			glm::vec3(-0.5f, -0.5f,  0.5f),		color,				glm::vec2(1.0f, 0.0f), // BOTTOM	LEFT	FRONT
			glm::vec3(-0.5f, -0.5f,  0.5f),		color,				glm::vec2(1.0f, 0.0f), // BOTTOM	LEFT	FRONT
			glm::vec3(-0.5f,  0.5f,  -0.5f),	color,				glm::vec2(0.0f, 1.0f), // TOP		LEFT	BACK 
			glm::vec3(-0.5f,  -0.5f,  -0.5f),	color,				glm::vec2(0.0f, 0.0f), // BOTTOM	LEFT	BACK 

			// RIGHT
			glm::vec3(0.5f,  0.5f,  -0.5f),		color,				glm::vec2(0.0f, 1.0f), // TOP		RIGHT	BACK 
			glm::vec3(0.5f,  0.5f,  0.5f),		color,				glm::vec2(1.0f, 1.0f), // TOP		RIGHT	FRONT
			glm::vec3(0.5f, -0.5f,  0.5f),		color,				glm::vec2(1.0f, 0.0f), // BOTTOM	RIGHT	FRONT
			glm::vec3(0.5f,  0.5f,  -0.5f),		color,				glm::vec2(0.0f, 1.0f), // TOP		RIGHT	BACK 
			glm::vec3(0.5f, -0.5f,  0.5f),		color,				glm::vec2(1.0f, 0.0f), // BOTTOM	RIGHT	FRONT
			glm::vec3(0.5f,  -0.5f,  -0.5f),	color,				glm::vec2(0.0f, 0.0f), // BOTTOM	RIGHT	BACK 

		};

		GLuint i[] = {
			// Передняя грань
			0, 1, 2,  2, 3, 0,

			// Задняя грань
			5, 4, 7,  7, 6, 5,

			// Левая грань
			4, 0, 3,  3, 7, 4,

			// Правая грань
			1, 5, 6,  6, 2, 1,

			// Верхняя грань
			3, 2, 6,  6, 7, 3,

			// Нижняя грань
			4, 5, 1,  1, 0, 4
		};


		setInitial(v, i, sizeof(v) / sizeof(Vertex), sizeof(i) / sizeof(GLuint));
	}
};

#endif // !HEADERS_PRIMITIVES_CUBE_H_