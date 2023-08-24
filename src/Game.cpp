#include "Game.hpp"
#include "check_gl.hpp"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "OBJ.hpp"

#ifndef OPENGLTUTOR_HOME 
#define OPENGLTUTOR_HOME
#endif

class Game::ConstantBuffer
{
public:
	glm::mat4x4 ViewMat;
	glm::mat4x4 projMat;

	OBJ Monkey;
};


Game::Game():CBuffer(std::make_unique<ConstantBuffer>()){}

Game::~Game() = default;

Game& Game::get() {
	static Game game; 
	return game;
}

void Game::set_window(GLFWwindow* window)
{
	m_window = window;
	glfwSetWindowUserPointer(window, this);
	m_inputCtl.register_callbacks(window);
}

void Game::Initialize()
{

	CBuffer->Monkey.load_obj(OPENGLTUTOR_HOME"Content/Monkey.obj");
	CHECK_GL(glEnable(GL_DEPTH_TEST));
	CHECK_GL(glEnable(GL_MULTISAMPLE));
	CHECK_GL(glEnable(GL_BLEND));
	CHECK_GL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	CHECK_GL(glEnable(GL_LIGHTING));
	CHECK_GL(glEnable(GL_LIGHT0));
	CHECK_GL(glEnable(GL_COLOR_MATERIAL));
	CHECK_GL(glEnable(GL_NORMALIZE));
	CHECK_GL(glEnable(GL_CULL_FACE));
	CHECK_GL(glCullFace(GL_BACK));
	CHECK_GL(glFrontFace(GL_CCW));
}

void Game::render()
{
	int width, height;
	glfwGetWindowSize(m_window, &width, &height);
	CHECK_GL(glViewport(0, 0, width, height));

	CHECK_GL(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));
	CHECK_GL(glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT));

	auto projection = m_inputCtl.get_projection_matrix();

	CHECK_GL(glMatrixMode(GL_PROJECTION));
	CHECK_GL(glLoadMatrixf(glm::value_ptr(projection)));

	auto view = m_inputCtl.get_view_matrix();
	glm::mat4x4 model(1.0f);

	glColor3f(0.9f, 0.6f, 0.1f);

	CHECK_GL(glMatrixMode(GL_MODELVIEW));
	CHECK_GL(glLoadMatrixf(glm::value_ptr(view * model)));
	CBuffer->Monkey.draw_obj(true);
}



