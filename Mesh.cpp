#include "Mesh.h"

Mesh::Mesh(Primitive* object, ShaderSubSystem* shader, const char* texturePath) {
	this->object = object;
	this->shader = shader;

	if (texturePath != nullptr) {
		this->texture = new TextureSubSystem(texturePath);
	}

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBindVertexArray(0);
	glUseProgram(0);
}

Mesh::~Mesh() {
	delete texture;
	delete object;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Mesh::Draw(GLenum textureID) {
	glBindVertexArray(VAO);
	if (textureID != NULL) {
		TextureSubSystem::Activate(textureID, texture->texture);
	}
	setUniformM4(shader->program, "model", glm::value_ptr(object->GetModel()));
	object->Draw();
}

void Mesh::BindAttribute(const GLchar* name, GLint size, GLsizei stride, GLvoid* pointer) {
	glBindVertexArray(VAO);
	bindVertexAttribute(this->shader->program, name, size, stride, pointer);
}