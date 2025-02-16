#ifndef HEADERS_GLOBAL_UNIFORM_H
#define HEADERS_GLOBAL_UNIFORM_H

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

void setUniform1i(GLuint program, const GLchar* name, GLuint value);
void setUniform1f(GLuint program, const GLchar* name, GLfloat value);
void setUniformM4(GLuint program, const GLchar* name, const glm::f32* value);

#endif // !HEADERS_GLOBAL_UNIFORM_H
 