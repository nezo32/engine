#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <stdexcept>
#include "debug.h"
#include "WindowSystem.h"
#include "ShaderSystem.h"
#include "InputSystem.h"
#include "RenderSystem.h"

class Game {
private:
	inline static WindowSystem* windowSystem;
	inline static ShaderSystem* shaderSystem;
	inline static InputSystem* inputSystem;
	inline static RenderSystem* renderSystem;

public:
	Game(
		WindowSystem* ws,
		ShaderSystem* ss,
		InputSystem* is,
		RenderSystem* rs
	);
	~Game();

	void MainLoop();
};