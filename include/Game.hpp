#pragma once
#include "check_gl.hpp"
#include <memory>
#include "InputCtl.hpp"


class Game {
public:
	Game();
	Game(Game&&) = delete;
	static Game& get();

	void set_window(GLFWwindow* g_window);
	void Initialize();
	void render();

public:
	~Game();
	

public:
	class ConstantBuffer;
	std::unique_ptr<ConstantBuffer> const CBuffer;

	InputCtl m_inputCtl;
	GLFWwindow* m_window;
};