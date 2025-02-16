#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <stdexcept>
#include "debug.h"
#include "WindowSystem.h"
#include "InputSystem.h"
#include "RenderSystem.h"

class Game {
private:
	inline static WindowSystem* windowSystem;
	inline static InputSystem* inputSystem;
	inline static RenderSystem* renderSystem;

	inline static Camera* cam;
public:
	Game(
		WindowSystem* ws,
		InputSystem* is,
		RenderSystem* rs
	);
	~Game();

	void MainLoop();
};