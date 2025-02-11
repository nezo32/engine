#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"

const int GLFW_MAJOR = 4;
const int GLFW_MINOR = 1;
const int GLFW_PROFILE = GLFW_OPENGL_CORE_PROFILE;
const int GLFW_RESIZE = GL_FALSE;

GLFWwindow* Window::window;

int Window::init(int width, int height, const char* title) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_RESIZE);

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (window == nullptr) {
		std::cerr << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, width, height);
	return 0;
}

void Window::terminate() {
	glfwTerminate();
}

bool Window::shoudClose() {
	return glfwWindowShouldClose(window);
}

void Window::close() {
	glfwSetWindowShouldClose(window, true);
}

void Window::swapBuffers() {
	glfwSwapBuffers(window);
}