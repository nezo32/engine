#ifndef HEADERS_INPUT_SYSTEM_H_
#define HEADERS_INPUT_SYSTEM_H_

#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <functional>
#include <algorithm>
#include "debug.h"

struct CursorState {
	double x;
	double y;

	double offsetX;
	double offsetY;

	double yaw;
	double pitch;

	double sensitivity;

	double lastX;
	double lastY;

	bool flag;
};

typedef std::function<void(GLFWwindow* window, CursorState* state)> cursorCallback;
typedef std::function<void(GLFWwindow* window)> mouseCallback;
typedef std::function<void(GLFWwindow* window)> keyboardCallback;

class InputSystem {
private:
	inline static InputSystem* staticPointer;
	CursorState* cursorState;

	std::vector<cursorCallback> cursorCallbacks;
	std::vector<mouseCallback> mouseCallbacks;
	std::vector<keyboardCallback> keyboardCallbacks;

	void cursorInput();
	void mouseInput();
	void keyboardInput();
public:
	GLFWwindow* window;

	InputSystem(GLFWwindow* window);
	~InputSystem();

	void Input();

	void ChangeCursorInputMode(int mode);
	int GetCursorInputMode();

	void ResetCursorState();

	int GetKeyDown(int key);
	int GetMouseButton(int button);

	void AddCursorCallback(cursorCallback cb);
	void AddMouseCallback(mouseCallback cb);
	void AddKeyboardCallback(keyboardCallback cb);
};

#endif // !HEADERS_INPUT_SYSTEM_H_