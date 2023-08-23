#pragma once
#include "check_gl.hpp"
#include <memory>

class Game {
public:
	Game();
	~Game();
	Game(Game&&) = delete;
};