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
	double lastX;
	double lastY;
	bool flag;
};

struct DeltaTime {
	float deltaTime;
	float currentTime;
	float lastTime;
};

typedef std::function<void(GLFWwindow* window, CursorState* state)> cursorCallback;
typedef std::function<void(GLFWwindow* window)> mouseCallback;
typedef std::function<void(GLFWwindow* window)> keyboardCallback;

class InputSystem {
private:
	inline static InputSystem* staticPointer;

	DeltaTime* deltaTime;
	CursorState* cursorState;

	std::vector<cursorCallback> cursorCallbacks;
	std::vector<mouseCallback> mouseCallbacks;
	std::vector<keyboardCallback> keyboardCallbacks;

	void cursorInput();
	void mouseInput();
	void keyboardInput();

	void updateDeltaTime();
public:
	GLFWwindow* window;

	InputSystem(GLFWwindow* window);
	~InputSystem();

	void Input();
	void ChangeCursorInputMode(int mode);

	int GetKeyDown(int key);
	int GetMouseButton(int button);

	void AddCursorCallback(cursorCallback cb);
	void AddMouseCallback(mouseCallback cb);
	void AddKeyboardCallback(keyboardCallback cb);
};