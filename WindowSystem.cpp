#include "WindowSystem.h"

const int GLFW_CTX_MAJOR = 4;
const int GLFW_CTX_MINOR = 6;
const int GLFW_RESIZE = GL_TRUE;

static void frameBufferResize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

WindowSystem::WindowSystem(int width, int height, const char* title) {
	this->width = width;
	this->height = height;
	this->title = title;
	frameBufferWidth = 0;
	frameBufferHeight = 0;

	// GLFW INIT
	if (glfwInit() == GLFW_FALSE) {
		std::cerr << "ERROR :: WindowSystem :: GLFW initialization failed" << "\n";
		throw std::exception();
	}

	// HINTS
	setHints();

	// WINDOW INIT
	initWindow();

	// GLEW INIT
	initGLEW();

	// RESIZE
	if (GLFW_RESIZE == GL_TRUE) {
		glfwSetFramebufferSizeCallback(window, frameBufferResize);
	}
}

WindowSystem::~WindowSystem() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void WindowSystem::setHints() {
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_CTX_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_CTX_MINOR);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_RESIZE);
}

void WindowSystem::initWindow() {
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (window == NULL) {
		std::cerr << "ERROR :: WindowSystem :: Failed to create GLFW window" << "\n";
		glfwTerminate();
		throw std::exception();
	}
	glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
	glViewport(0, 0, frameBufferWidth, frameBufferHeight);
	glfwMakeContextCurrent(window);
}

void WindowSystem::initGLEW() {
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cerr << "ERROR :: WindowSystem :: GLEW initialization failed" << "\n";
		glfwTerminate();
		throw std::exception();
	}
}

bool WindowSystem::ShouldClose() {
	return glfwWindowShouldClose(window);
}

void WindowSystem::SetShouldClose(bool flag) {
	glfwSetWindowShouldClose(window, flag);
}

void WindowSystem::PollEvents() {
	glfwPollEvents();
}

void WindowSystem::SwapBuffers() {
	glfwSwapBuffers(window);
}

