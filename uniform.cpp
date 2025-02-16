#include "uniform.h"

void setUniform1i(GLuint program, const GLchar* name, GLuint value) {
    glUniform1i(glGetUniformLocation(program, name), value);
}

void setUniform1f(GLuint program, const GLchar* name, GLfloat value) {
    glUniform1f(glGetUniformLocation(program, name), value);
}

void setUniformM4(GLuint program, const GLchar* name, const glm::f32* value) {
    glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, value);
}