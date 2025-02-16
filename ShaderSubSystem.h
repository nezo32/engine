#ifndef HEADERS_SHADER_SUB_SYSTEM_H_
#define HEADERS_SHADER_SUB_SYSTEM_H_

#include <glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "typedefs.h"

class ShaderSubSystem {
private:
	static const ushort LOG_SIZE = 1024;
	char log[LOG_SIZE] = { '\0' };
	
	std::string tempSource;

	void loadSource(const char* path);
	GLuint loadShader(GLenum type, const char* path);

	GLint linkProgram(GLuint vertex, GLuint frag, GLuint geometry);

public:
	GLuint program;

	GLuint vertex = 0;
	GLuint fragment = 0;
	GLuint geometry = 0;

	void ClearShaders();
	void Use();
	ShaderSubSystem(const char* vertexPath, const char* fragmentPath, const char* geometryPath = "");

	ShaderSubSystem(GLuint vertex, GLuint fragment, const char* geometryPath = "");

	ShaderSubSystem(GLuint vertex, const char* fragmentPath, const char* geometryPath = "");
	ShaderSubSystem(const char* vertexPath, GLuint fragment, const char* geometryPath = "");

	~ShaderSubSystem();
};

#endif // !HEADERS_SHADER_SUB_SYSTEM_H_