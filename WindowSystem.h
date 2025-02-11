#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <stdexcept>

const int GLFW_CTX_MAJOR = 4;
const int GLFW_CTX_MINOR = 6;
const int GLFW_RESIZE = GL_FALSE;

class WindowSystem {
private:
	int initialWidth;
	int initialHeight;

	int frameBufferWidth = 0;
	int frameBufferHeight = 0;
public:
	GLFWwindow* window;

	WindowSystem(int width, int height, const char* title) {
		initialWidth = width;
		initialHeight = height;

		if (glfwInit() == GLFW_FALSE) {
			std::cerr << "ERROR :: WindowSystem.h :: GLFW initialization failed" << "\n";
		}

		// HINTS
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_CTX_MAJOR);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_CTX_MINOR);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_RESIZE);

		// WINDOW INIT
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
		glViewport(0, 0, frameBufferWidth, frameBufferHeight);
		glfwMakeContextCurrent(window);

		// GLEW
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK) {
			std::cerr << "ERROR :: WindowSystem.h :: GLEW initialization failed" << "\n";
			glfwTerminate();
		}
	}
	~WindowSystem() {
		glfwTerminate();
	}

	bool shouldClose() const {
		return glfwWindowShouldClose(window);
	}

	void setShouldClose(bool flag) const {
		glfwSetWindowShouldClose(window, flag);
	}

	void pollEvents() const {
		glfwPollEvents();
	}

	void swapBuffers() const {
		glfwSwapBuffers(window);
	}
};