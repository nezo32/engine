#include "RenderSystem.h"

RenderSystem::RenderSystem(WindowSystem* ws, ShaderSubSystem* coreShader, std::vector<Mesh*>& meshes, Light<Circle>* light) {
	this->ws = ws;
	this->coreShader = coreShader;
	this->meshes = meshes;
	this->lightSource = light;

	configureOpenGLOptions();
	TextureSubSystem::ConfigTextureParams();
}

RenderSystem::~RenderSystem() {
	meshes.clear();
}

void RenderSystem::Render() {
	float x = (float)glfwGetTime();
	lightSource->Move(glm::vec3(sin(x) * cos(x) * 0.1f, 0.f, 0.f));

	for (Mesh* mesh : meshes) {
		mesh->UseShader();

		camera->Use(mesh->GetShaderID());
		usePerspective(mesh->GetShaderID());

		mesh->BindUniform("light_color", lightSource->GetColor());
		mesh->BindUniform("light_pos", lightSource->GetPosition());
		mesh->BindUniform("cam_pos", camera->position);

		mesh->Draw();
	}
}

void RenderSystem::Clear() {
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void RenderSystem::usePerspective(GLuint program) {
	glm::mat4 projection = glm::perspective(glm::radians(fov), ws->GetRatio(), near, far);
	setUniformM4(program, "projection", glm::value_ptr(projection));
}

void RenderSystem::configureOpenGLOptions(){
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
