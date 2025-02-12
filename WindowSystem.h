#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <stdexcept>

class WindowSystem {
private:
	int width;
	int height;
	const char* title;

	int frameBufferWidth;
	int frameBufferHeight;

	void setHints();
	void initWindow();
	void initGLEW();
public:
	GLFWwindow* window;

	WindowSystem(int width, int height, const char* title);
	~WindowSystem();

	bool ShouldClose();
	void SetShouldClose(bool flag);

	void PollEvents();
	void SwapBuffers();
};