#ifndef HEADERS_PRIMITIVES_PRIMITIVE_H_
#define HEADERS_PRIMITIVES_PRIMITIVE_H_

#include <vector>
#include <algorithm>
#include <iostream>
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "vertex.h"
#include "uniform.h"

enum DrawType {
	DRAW_TYPE_NULL,
	DRAW_TYPE_ARRAY,
	DRAW_TYPE_ELEMENT
};

class Primitive {
private:
	void drawArrays();
	void drawElements();

	void preferDraw(DrawType type);
protected:
	DrawType preferableDrawType = DRAW_TYPE_ELEMENT;

	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	glm::mat4 model = glm::mat4(1.f);

	void setInitial(const Vertex* v, const GLuint* i, size_t nV, size_t nI);
	void setInitial(std::vector<Vertex>& v, std::vector<GLuint>& i);
public:
	Primitive();
	~Primitive();

	void Draw(DrawType type = DRAW_TYPE_NULL);

	glm::mat4 Rotate(float radians, const glm::vec3& axis);
	glm::mat4 Move(const glm::vec3& axis);
	glm::mat4 Scale(const glm::vec3& axis);

	inline glm::mat4 GetModel() { return model; }
	inline Vertex* GetVertices() { return vertices.data(); }
	inline GLuint* GetIndices() { return indices.data(); }
	inline GLsizei GetVerticesCount() { return static_cast<GLsizei>(vertices.size()); }
	inline GLsizei GetIndicesCount() { return static_cast<GLsizei>(indices.size()); }
};

#endif // !HEADERS_PRIMITIVES_PRIMITIVE_H_