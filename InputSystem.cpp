#include "InputSystem.h"

InputSystem::InputSystem(GLFWwindow* window) {
	this->window = window;

	deltaTime = new DeltaTime{
		0.f,
		0.f,
		0.f
	};

	cursorState = new CursorState{
		0.0, 0.0,
		0.0, 0.0,
		0.0, 0.0,
		true
	};

	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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

	// LAST
	cursorState->lastX = cursorState->x;
	cursorState->lastY = cursorState->y;

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

void InputSystem::updateDeltaTime() {
	deltaTime->currentTime = static_cast<float>(glfwGetTime());
	deltaTime->deltaTime = deltaTime->currentTime - deltaTime->lastTime;
	deltaTime->lastTime = deltaTime->currentTime;

#ifdef DEBUG_DELTA_TIME
	std::cout << deltaTime->deltaTime << "\n";
#endif // DEBUG_DELTA_TIME
}

void InputSystem::Input() {
	updateDeltaTime();
	cursorInput();
	mouseInput();
	keyboardInput();
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

int InputSystem::GetKeyDown(int key) {
	return glfwGetKey(window, key);
}

int InputSystem::GetMouseButton(int button) {
	return glfwGetMouseButton(window, button);
}