#ifndef HEADERS_ENTITIES_MESH_H_
#define HEADERS_ENTITIES_MESH_H_

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include "ShaderSubSystem.h"
#include "TextureSubSystem.h"
#include "Primitive.h"
#include "Light.h"
#include "uniform.h"
#include "attribute.h"

class Mesh {
private:
	Primitive* object;
	ShaderSubSystem* shader;
	TextureSubSystem* texture = nullptr;

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
public:
	Mesh(Primitive* object, ShaderSubSystem* shader, const char* texturePath = nullptr);
	~Mesh();

	void Draw(GLenum textureID = NULL);
	/**
	Usage:
	mesh.BindAttribute("vertex_position", 3, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position))
	*/
	void BindAttribute(const GLchar* name, GLint size, GLsizei stride, GLvoid* pointer);
};

#endif // !HEADERS_ENTITIES_MESH_H_