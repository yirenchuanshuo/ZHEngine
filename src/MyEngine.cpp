// MyEngine.cpp: 定义应用程序的入口点。
//
#pragma once
#include "check_gl.hpp" // includes glad/glad.h
#include <GLFW/glfw3.h> // must be placed behind glad/glad.h
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include "OBJ.hpp"
#include "Game.hpp"
using namespace std;




int main()
{
	//初始化
	glfwInit();
	if (!glfwInit())
	{
		const char* errmsg;
		glfwGetError(&errmsg);
		if (!errmsg) errmsg = "(no error)";
		return -1;
	}
	constexpr int version = 20;
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
	glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version / 10);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version % 10);
	if (version >= 33) {
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	
	//画一个窗口
	GLFWwindow* window = glfwCreateWindow(1024, 768, "Triangles", NULL, NULL);
	//异常处理
	if (!window)
	{
		check_gl::opengl_show_glfw_error_diagnose();
		glfwTerminate();
		return -1;
	}
	//把当前窗口设为上下文
	glfwMakeContextCurrent(window);
	gladLoadGL();
	if (!gladLoadGL())
	{
		glfwTerminate();
		cout << "GLAD failed to load GL functions\n";
		return -1;
	}
	check_gl::opengl_try_enable_debug_message();
	std::cerr << "OpenGL version: " << (const char*)glGetString(GL_VERSION) << '\n';

	glfwSwapInterval(1);

	Game& game = Game::get();
	game.set_window(window);

	game.Initialize();
	
	
	while (!glfwWindowShouldClose(window)) {
		// render graphics
		game.render();
		// refresh screen
		//提交画图Buffer
		glfwSwapBuffers(window);
		//拉取操作系统事件
		glfwPollEvents();
	}
	glfwTerminate();
	
	return 0;
}
