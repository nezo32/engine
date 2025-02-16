#include "RenderSystem.h"

RenderSystem::RenderSystem(WindowSystem* ws, ShaderSubSystem* coreShader, std::vector<Mesh*>& meshes) {
	this->ws = ws;
	this->coreShader = coreShader;
	this->meshes = meshes;

	configureOpenGLOptions();
	TextureSubSystem::ConfigTextureParams();
}

RenderSystem::~RenderSystem() {
	meshes.clear();
}

void RenderSystem::Render() {
	// USE CORE SHADER
	coreShader->Use();

	// SETUP SPACES
	camera->Use(coreShader->program);
	usePerspective();
	
	// DRAW MASHES
	for (Mesh* mesh : meshes) {
		mesh->Draw();
	}
}

void RenderSystem::Clear() {
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void RenderSystem::usePerspective() {
	glm::mat4 projection = glm::perspective(glm::radians(fov), ws->GetRatio(), near, far);
	setUniformM4(coreShader->program, "projection", glm::value_ptr(projection));
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
