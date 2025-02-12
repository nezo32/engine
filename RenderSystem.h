#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "vertex.h"

class RenderSystem
{
private:
	GLuint program;
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	inline static Vertex vertices[] = {
		// POSITION							// COLOR						// TEXTURE POSITION
		glm::vec3(0.f, 0.5f, 0.f),			glm::vec3(1.0f, 0.f, 0.f),		glm::vec2(0.f, 1.f),
		glm::vec3(-0.5f, -0.5f, 0.f),		glm::vec3(0.0f, 1.f, 0.f),		glm::vec2(0.f, 0.f),
		glm::vec3(0.5f, -0.5f, 0.f),		glm::vec3(0.0f, 0.f, 1.f),		glm::vec2(1.f, 0.f),
	};
	inline static unsigned verticesCount = sizeof(vertices) / sizeof(Vertex);

	inline static GLuint indices[] = { 0, 1, 2 };
	inline static unsigned int indicesCount = sizeof(indices) / sizeof(GLuint);

	void configureOpenGLOptions();
public:
	RenderSystem(GLuint program);
	~RenderSystem();

	void Render();
	void Clear();
};