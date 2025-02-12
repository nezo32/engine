#include <glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "typedefs.h"

class ShaderSystem {
private:
	static const ushort LOG_SIZE = 1024;
	char log[LOG_SIZE] = { '\0' };
	
	std::string tempSource;

	void loadSource(const char* path);
	GLuint loadShader(GLenum type, const char* path);

	GLint linkProgram(GLuint vertex, GLuint frag, GLuint geometry);

public:
	GLuint program;

	ShaderSystem(const char* vertexPath, const char* fragmentPath, const char* geometryPath = "");
	~ShaderSystem();
};