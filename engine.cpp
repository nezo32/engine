#include "Game.h"
#include "Cube.h"
#include "Quad.h"
#include "Sphere.h"
#include "Circle.h"
#include "Light.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const bool WINDOW_FULLSCREEN = false;
const char* WINDOW_TITLE = "fuck";

int main() {
	try {
		// WINDOW SYSTEM
		WindowSystem* ws = new WindowSystem(WINDOW_TITLE, WINDOW_FULLSCREEN, WINDOW_WIDTH, WINDOW_HEIGHT);

		// CORE SHADER
		ShaderSubSystem* coreShader = new ShaderSubSystem("vertex_core.vert", "fragment_core.frag");
		ShaderSubSystem* lightEntityShader = new ShaderSubSystem(coreShader->vertex, "light_entity.frag");

		// MESHES INITIALIZATION
		std::vector<Mesh*> meshes;

		Mesh* cubeMesh1 = new Mesh(new Cube(glm::vec3(1.f, 0.5f, 0.25f)), coreShader);

		Cube* cube = new Cube();
		cube->Move({ 1.5f, 0.f, 1.f });
		cube->Rotate(glm::radians(15.f), { 1.f, 0.f, 1.f });
		Mesh* cubeMesh2 = new Mesh(cube, coreShader);

		Sphere* sphere = new Sphere();
		sphere->Move({ -1.5f, 0.f, 2.f });
		Mesh* sphereMesh = new Mesh(sphere, coreShader);

		glm::vec3 lightColor = glm::vec3(1.f, 1.f, 1.f);
		Light<Circle>* light = new Light<Circle>(lightColor);
		light->Move({ -7.f, 4.f, 3.f });
		light->Rotate(glm::radians(90.f), { 1.f, 0.f, 0.f });
		light->Scale({ 2.f, 2.f, 2.f });
 		Mesh* lightMesh = new Mesh(light, lightEntityShader);

		Quad* quad = new Quad();
		quad->Move({ 0.f, -0.5f, 0.f });
		quad->Rotate(glm::radians(90.f), {1.f, 0.f, 0.f});
		quad->Scale({ 1000.f, 1000.f, 1000.f });
		Mesh* quadMesh = new Mesh(quad, coreShader);

		meshes.push_back(lightMesh);
		meshes.push_back(cubeMesh1);
		meshes.push_back(cubeMesh2);
		meshes.push_back(sphereMesh);
		meshes.push_back(quadMesh);


		for (Mesh* mesh : meshes) {
			mesh->BindAttribute("vertex_position", 3, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
			mesh->BindAttribute("vertex_color", 3, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
			mesh->BindAttribute("vertex_normal", 3, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
			mesh->BindAttribute("vertex_textureCoordinate", 2, sizeof(Vertex), (GLvoid*)offsetof(Vertex, textureCoordinate));
		}

		// RENDER SYSTEM
		RenderSystem* rs = new RenderSystem(ws, coreShader, meshes, light);

		// INPUT SYSTEM
		InputSystem* is = new InputSystem(ws->window);

		// GAME INITIALIZATION
		Game game(ws, is, rs);

		// MAIN LOOP
		game.MainLoop();

		// CLEARANCE
		delete coreShader;
		delete lightEntityShader;
		for (Mesh* mesh : meshes) {
			delete mesh;
		}
		meshes.clear();

		return 0;
	}
	catch (std::exception e) {
		std::cin.get();
		return 1;
	}
}