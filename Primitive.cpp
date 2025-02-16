#include "Primitive.h"

Primitive::Primitive() {
	this->model = glm::mat4(1.f);
}

Primitive::~Primitive() {
	vertices.clear();
	indices.clear();
}

void Primitive::drawArrays() {
	glDrawArrays(GL_TRIANGLES, 0, GetVerticesCount());
}

void Primitive::drawElements() {
	glDrawElements(GL_TRIANGLES, GetIndicesCount(), GL_UNSIGNED_INT, 0);
}

void Primitive::preferDraw(DrawType type) {
	if (type == DRAW_TYPE_ARRAY)
		drawArrays();
	else
		drawElements();
}

void Primitive::Draw(DrawType type) {
	glBufferData(GL_ARRAY_BUFFER, GetVerticesCount() * sizeof(Vertex), GetVertices(), GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetIndicesCount() * sizeof(GLuint), GetIndices(), GL_STATIC_DRAW);

	if (type == DRAW_TYPE_NULL) {
		preferDraw(preferableDrawType);
		return;
	}

	preferDraw(type);
}

glm::mat4 Primitive::Rotate(float radians, const glm::vec3& axis) {
	model = glm::rotate(model, radians, axis);
	return model;
}

glm::mat4 Primitive::Move(const glm::vec3& axis) {
	model = glm::translate(model, axis);
	return model;
}

glm::mat4 Primitive::Scale(const glm::vec3& axis) {
	model = glm::scale(model, axis);
	return model;
}

void Primitive::setInitial(const Vertex* v, const GLuint* i, size_t nV, size_t nI) {
	for (size_t index = 0; index < nV; index++)
		vertices.push_back(v[index]);

	for (size_t index = 0; index < nI; index++)
		indices.push_back(i[index]);
}

void Primitive::setInitial(std::vector<Vertex>& v, std::vector<GLuint>& i) {
	vertices = v;
	indices = i;
}