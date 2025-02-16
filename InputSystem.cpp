#include "InputSystem.h"

InputSystem::InputSystem(GLFWwindow* window) {
	this->window = window;

	cursorState = new CursorState{
		0.0, 0.0,
		0.0, 0.0,
		-90.0, 0.0,
		0.1,
		0.0, 0.0,
		true
	};

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	staticPointer = this;
}

InputSystem::~InputSystem() {
	cursorCallbacks.clear();
	mouseCallbacks.clear();
	keyboardCallbacks.clear();
	delete cursorState;
}

void InputSystem::cursorInput() {
	glfwGetCursorPos(window, &cursorState->x, &cursorState->y);

	if (cursorState->flag) {
		cursorState->lastX = cursorState->x;
		cursorState->lastY = cursorState->y;
		cursorState->flag = false;
	}

	// OFFSET
	cursorState->offsetX = cursorState->x - cursorState->lastX;
	cursorState->offsetY = cursorState->y - cursorState->lastY;

	// SENSITIVITY
	cursorState->offsetX *= cursorState->sensitivity;
	cursorState->offsetY *= cursorState->sensitivity;

	// LAST
	cursorState->lastX = cursorState->x;
	cursorState->lastY = cursorState->y;

	// YAW PITCH
	cursorState->yaw += cursorState->offsetX;
	cursorState->pitch += cursorState->offsetY;

	if (cursorState->pitch > 89.0)
		cursorState->pitch = 89.0;
	if (cursorState->pitch < -89.0)
		cursorState->pitch = -89.0;

	// CENTRALIZE
	int width = 0;
	int height = 0;
	glfwGetWindowSize(window, &width, &height);

	cursorState->x = float(width) / 2.f;
	cursorState->y = float(height) / 2.f;

	std::for_each(cursorCallbacks.begin(), cursorCallbacks.end(), [](cursorCallback cb) {
		cb(staticPointer->window, staticPointer->cursorState);
	});
}

void InputSystem::mouseInput() {
	std::for_each(mouseCallbacks.begin(), mouseCallbacks.end(), [](mouseCallback cb) {
		cb(staticPointer->window);
	});
}

void InputSystem::keyboardInput() {
	std::for_each(keyboardCallbacks.begin(), keyboardCallbacks.end(), [](keyboardCallback cb) {
		cb(staticPointer->window);
	});
} 

void InputSystem::Input() {
	if (glfwGetWindowAttrib(window, GLFW_FOCUSED) == GL_FALSE) return;
	keyboardInput();
	mouseInput();
	cursorInput();
}

void InputSystem::AddCursorCallback(cursorCallback cb) {
	cursorCallbacks.push_back(cb);
}

void InputSystem::AddMouseCallback(mouseCallback cb) {
	mouseCallbacks.push_back(cb);
}

void InputSystem::AddKeyboardCallback(keyboardCallback cb) {
	keyboardCallbacks.push_back(cb);
}


void InputSystem::ChangeCursorInputMode(int mode) {
	glfwSetInputMode(window, GLFW_CURSOR, mode);
}

int InputSystem::GetCursorInputMode() {
	return glfwGetInputMode(window, GLFW_CURSOR);
}

void InputSystem::ResetCursorState() {
	int width = 0;
	int height = 0;
	glfwGetWindowSize(window, &width, &height);

	float wc = float(width) / 2.f;
	float wh = float(height) / 2.f;

	cursorState->x = wc;
	cursorState->y = wh;
	cursorState->lastX = wc;
	cursorState->lastY = wh;
	cursorState->offsetX = 0;
	cursorState->offsetY = 0;
	cursorState->flag = true;
	glfwSetCursorPos(window, wc, wh);
}

int InputSystem::GetKeyDown(int key) {
	return glfwGetKey(window, key);
}

int InputSystem::GetMouseButton(int button) {
	return glfwGetMouseButton(window, button);
}