#include "WindowSystem.h"

const int GLFW_CTX_MAJOR = 4;
const int GLFW_CTX_MINOR = 6;
const int GLFW_RESIZE = GLFW_TRUE;

static void frameBufferResize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

WindowSystem::WindowSystem(const char* title, bool fullscreen, int width, int height) {
	this->width = width;
	this->height = height;
	this->title = title;
	this->fullscreen = fullscreen;
	frameBufferWidth = 0;
	frameBufferHeight = 0;

	// GLFW INIT
	if (glfwInit() == GLFW_FALSE) {
		std::cerr << "ERROR :: WindowSystem :: GLFW initialization failed" << "\n";
		throw std::exception();
	}

	monitor = glfwGetPrimaryMonitor();
	mode = glfwGetVideoMode(monitor);

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

	// DELTA TIME
	deltaTime = new DeltaTime{0.f, 0.f, 0.f};
}

WindowSystem::~WindowSystem() {
	delete deltaTime;
	glfwDestroyWindow(window);
	glfwTerminate();
}

void WindowSystem::setHints() {
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_CTX_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_CTX_MINOR);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_RESIZE);

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
}

void WindowSystem::initWindow() {
	int w = mode->width;
	int h = mode->height;
	GLFWmonitor* m = NULL;

	float offsetX = 0;
	float offsetY = 0;

	if (width) {
		w = width;
	}
	if (height) {
		h = height;
	}

	if (fullscreen) {
		m = monitor;
	}

	window = glfwCreateWindow(w, h, title, m, NULL);
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

float WindowSystem::GetRatio() {
	GLint m_viewport[4];
	glGetIntegerv(GL_VIEWPORT, m_viewport);

	return float(m_viewport[2]) / float(m_viewport[3]);
}

bool WindowSystem::ShouldClose() {
	return glfwWindowShouldClose(window);
}

void WindowSystem::SetShouldClose(bool flag) {
	glfwSetWindowShouldClose(window, flag);
}

void WindowSystem::UpdateDeltaTime() {
	deltaTime->currentTime = static_cast<float>(glfwGetTime());
	deltaTime->deltaTime = deltaTime->currentTime - deltaTime->lastTime;
	deltaTime->lastTime = deltaTime->currentTime;

#ifdef DEBUG_DELTA_TIME
	std::cout << deltaTime->deltaTime << "\n";
#endif // DEBUG_DELTA_TIME
}

void WindowSystem::PollEvents() {
	glfwPollEvents();
}

void WindowSystem::SwapBuffers() {
	glfwSwapBuffers(window);
}

