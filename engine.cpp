#include "Game.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main() {
	try {
		// INITIALIZATION
		WindowSystem* ws = new WindowSystem(WINDOW_WIDTH, WINDOW_HEIGHT, "fuck");
		ShaderSystem* ss = new ShaderSystem("vertex_core.vert", "fragment_core.frag");
		RenderSystem* rs = new RenderSystem(ss->program);
		InputSystem* is = new InputSystem(ws->window);

		// GAME INITIALIZATION
		Game game(ws, ss, is, rs);

		// MAIN LOOP
		game.MainLoop();

		return 0;
	}
	catch (std::exception e) {
		return 1;
	}
}