#ifndef HEADERS_WINDOW_SYSTEM_H_
#define HEADERS_WINDOW_SYSTEM_H_

#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <stdexcept>

struct DeltaTime {
	float deltaTime;
	float currentTime;
	float lastTime;
};

class WindowSystem {
private:
	const char* title;

	int frameBufferWidth;
	int frameBufferHeight;

	void setHints();
	void initWindow();
	void initGLEW();
public:
	int width;
	int height;
	bool fullscreen;

	GLFWwindow* window;
	GLFWmonitor* monitor;
	const GLFWvidmode* mode;

	DeltaTime* deltaTime;

	WindowSystem(const char* title, bool fullscreen = false, int width = NULL, int height = NULL);
	~WindowSystem();

	float GetRatio();

	bool ShouldClose();
	void SetShouldClose(bool flag);

	void UpdateDeltaTime();

	void PollEvents();
	void SwapBuffers();
};

#endif // !HEADERS_WINDOW_SYSTEM_H_