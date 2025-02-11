#include "WindowSystem.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main() {
	// INITIALIZATION
	WindowSystem ws(WINDOW_WIDTH, WINDOW_HEIGHT, "fuck");

	while (!ws.shouldClose()) {
		// UPDATE EVENTS
		ws.pollEvents();

		// SWAP BUFFERS
		ws.swapBuffers();
	}

	return 0;
}