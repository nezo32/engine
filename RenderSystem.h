#ifndef HEADERS_RENDER_SYSTEM_H_
#define HEADERS_RENDER_SYSTEM_H_

#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "vertex.h"
#include "uniform.h"
#include "TextureSubSystem.h"
#include "ShaderSubSystem.h"
#include "WindowSystem.h"
#include "Camera.h"
#include "Mesh.h"
#include "Light.h"
#include "Circle.h"

class RenderSystem
{
private:
	WindowSystem* ws;
	Camera* camera;
	ShaderSubSystem* coreShader;

	std::vector<Mesh*> meshes;
	Light<Circle>* lightSource;

	float fov = 45.f;
	float near = 0.1f;
	float far = 1000.f;

	void usePerspective(GLuint program);
	void configureOpenGLOptions();
public:
	RenderSystem(WindowSystem* ws, ShaderSubSystem* coreShader, std::vector<Mesh*>& meshes, Light<Circle>* light);
	~RenderSystem();

	void Render();
	void Clear();

	inline void BindCamera(Camera* cam) { camera = cam; };
};

#endif // !HEADERS_RENDER_SYSTEM_H_