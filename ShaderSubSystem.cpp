#include "ShaderSubSystem.h"

ShaderSubSystem::ShaderSubSystem(const char* vertexPath, const char* fragmentPath, const char* geometryPath) {
	program = glCreateProgram();

	if (strcmp(vertexPath, "") != 0)
		vertex = loadShader(GL_VERTEX_SHADER, vertexPath);
	if (strcmp(geometryPath, "") != 0)
		geometry = loadShader(GL_GEOMETRY_SHADER, geometryPath);
	if (strcmp(fragmentPath, "") != 0)
		fragment = loadShader(GL_FRAGMENT_SHADER, fragmentPath);

	tempSource.clear();
	linkProgram(vertex, fragment, geometry);
}

ShaderSubSystem::~ShaderSubSystem() {
	ClearShaders();
	glDeleteProgram(program);
}

void ShaderSubSystem::Use() {
 	glUseProgram(program);
}

void ShaderSubSystem::ClearShaders() {
	glDeleteShader(vertex);
	glDeleteShader(geometry);
	glDeleteShader(fragment);
}

void ShaderSubSystem::loadSource(const char* path) {
	std::ifstream file;
	std::stringstream stream;

	file.open(path);
	if (file.is_open())
		stream << file.rdbuf();
	else {
		std::cerr << "ERROR :: ShaderSystem :: Failed to open file - '" << path << "'\n";
		throw std::exception();
	}

	file.close();

	tempSource = stream.str();
}

GLuint ShaderSubSystem::loadShader(GLenum type, const char* path) {
	memset(this->log, 0, LOG_SIZE);
	GLint success;

	loadSource(path);
	GLuint shader = glCreateShader(type);
	const GLchar* src = tempSource.c_str();
	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, LOG_SIZE, NULL, this->log);
		std::cerr << "ERROR :: ShaderSystem :: Failed to compile shader - '" << path << "'\n";
		std::clog << this->log << "\n";
		throw std::exception();
	}

	return shader;
}

GLint ShaderSubSystem::linkProgram(GLuint vertex, GLuint fragment, GLuint geometry) {
	memset(this->log, 0, LOG_SIZE);
	GLint success;

	if (vertex)
		glAttachShader(program, vertex);

	if (geometry)
		glAttachShader(program, geometry);

	if (fragment)
		glAttachShader(program, fragment);

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, LOG_SIZE, NULL, this->log);
		std::cerr << "ERROR :: ShaderSystem :: Failed to link program" << "\n";
		std::clog << this->log << "\n";
		throw std::exception();
	}

	return success;
}