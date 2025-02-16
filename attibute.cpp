#include "attribute.h"

void bindVertexAttribute(GLuint program, const GLchar* name, GLint size, GLsizei stride, GLvoid* pointer) {
	GLuint location = glGetAttribLocation(program, name);
	glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, stride, pointer);
	glEnableVertexAttribArray(location);
}