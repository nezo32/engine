#include "Game.h"

Game::Game(WindowSystem* ws, ShaderSystem* ss, InputSystem* is, RenderSystem* rs) {
	this->windowSystem = ws;
	this->shaderSystem = ss;
	this->inputSystem = is;
	this->renderSystem = rs;

	inputSystem->AddKeyboardCallback([](GLFWwindow* w) {
		if (inputSystem->GetKeyDown(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			windowSystem->SetShouldClose(true);
		}
	});
#ifdef DEBUG_CURSOR_POSITION
	inputSystem->AddCursorCallback([](GLFWwindow* w, CursorState* s) {
		std::cout << "X: " << s->x << " - Y: " << s->y << "\n";
	});
#endif // DEBUG_CURSOR_POSITION
}

Game::~Game() {
	delete renderSystem;
	delete shaderSystem;
	delete inputSystem;
	delete windowSystem;
}

void Game::MainLoop() {
	while (!windowSystem->ShouldClose()) {
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