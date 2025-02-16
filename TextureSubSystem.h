#ifndef HEADERS_TEXTURE_SUB_SYSTEM_H_
#define HEADERS_TEXTURE_SUB_SYSTEM_H_


#include <glew.h>
#include <glfw3.h>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <SOIL2.h>

class TextureSubSystem {
private:
public:
	int width = 0;
	int height = 0;
	GLuint texture = 0;

	TextureSubSystem(const char* path);
	~TextureSubSystem();

	static void ConfigTextureParams();
	static void SetUniformID(GLuint program, GLuint id, const GLchar* name);
	static void Activate(GLenum type, GLuint texture);
};

#endif // !HEADERS_TEXTURE_SUB_SYSTEM_H_