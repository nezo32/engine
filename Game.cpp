#include "Game.h"

Game::Game(WindowSystem* ws, InputSystem* is, RenderSystem* rs) {
	this->windowSystem = ws;
	this->inputSystem = is;
	this->renderSystem = rs;

	cam = new Camera();
	cam->position = glm::vec3( 0.f, 0.f, 3.f );
	rs->BindCamera(cam);

	static int oldState = GLFW_RELEASE;
	inputSystem->AddKeyboardCallback([](GLFWwindow* w) {
		if (inputSystem->GetKeyDown(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			windowSystem->SetShouldClose(true);
		}

		if (inputSystem->GetKeyDown(GLFW_KEY_SPACE) == GLFW_PRESS)
			cam->position += glm::vec3(0.f, 1.f, 0.f) * cam->speed * windowSystem->deltaTime->deltaTime;
		if (inputSystem->GetKeyDown(GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
			cam->position -= glm::vec3(0.f, 1.f, 0.f) * cam->speed * windowSystem->deltaTime->deltaTime;
		
		if (inputSystem->GetKeyDown(GLFW_KEY_W) == GLFW_PRESS)
			cam->position += glm::vec3(cam->front.x, 0.f, cam->front.z) * cam->speed * windowSystem->deltaTime->deltaTime;
		if (inputSystem->GetKeyDown(GLFW_KEY_S) == GLFW_PRESS)
			cam->position -= glm::vec3(cam->front.x, 0.f, cam->front.z) * cam->speed * windowSystem->deltaTime->deltaTime;
		if (inputSystem->GetKeyDown(GLFW_KEY_A) == GLFW_PRESS)
			cam->position -= glm::normalize(glm::cross(cam->front, cam->worldUp)) * cam->speed * windowSystem->deltaTime->deltaTime;
		if (inputSystem->GetKeyDown(GLFW_KEY_D) == GLFW_PRESS)
			cam->position += glm::normalize(glm::cross(cam->front, cam->worldUp)) * cam->speed * windowSystem->deltaTime->deltaTime;

		int newState = inputSystem->GetKeyDown(GLFW_KEY_LEFT_ALT);

		if (newState == GLFW_RELEASE && oldState == GLFW_PRESS && inputSystem->GetCursorInputMode() == GLFW_CURSOR_DISABLED) {
			inputSystem->ResetCursorState();
			inputSystem->ChangeCursorInputMode(GLFW_CURSOR_NORMAL);
		}
		else if (newState == GLFW_RELEASE && oldState == GLFW_PRESS && inputSystem->GetCursorInputMode() == GLFW_CURSOR_NORMAL) {
			inputSystem->ResetCursorState();
			inputSystem->ChangeCursorInputMode(GLFW_CURSOR_DISABLED);
		}

		oldState = newState;

	});


	inputSystem->AddCursorCallback([](GLFWwindow* w, CursorState* s) {
		cam->ChangeDirection((float)s->yaw, (float)s->pitch);
#ifdef DEBUG_CURSOR_POSITION
		std::cout << "X: " << s->x << " - Y: " << s->y << " - DX: " << s->offsetX << " - DY: " << s->offsetY << "\n";
#endif // DEBUG_CURSOR_POSITION
	});
}

Game::~Game() {
	delete cam;

	delete renderSystem;
	delete inputSystem;
	delete windowSystem;
}

void Game::MainLoop() {
	while (!windowSystem->ShouldClose()) {
		windowSystem->UpdateDeltaTime();

		// INPUTS
		inputSystem->Input();

		// CLEAR
		renderSystem->Clear();

		// RENDER
		renderSystem->Render();

		// UPDATE WINDOW
		windowSystem->SwapBuffers();
		windowSystem->PollEvents();
	}
}