#ifndef HEADERS_GLOBAL_ATTRIBUTE_H
#define HEADERS_GLOBAL_ATTRIBUTE_H

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>

void bindVertexAttribute(GLuint program, const GLchar* name, GLint size, GLsizei stride, GLvoid* pointer);

#endif // !HEADERS_GLOBAL_ATTRIBUTE_H
