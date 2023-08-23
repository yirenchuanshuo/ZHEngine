// MyEngine.cpp: 定义应用程序的入口点。
//
#pragma once
#include "check_gl.hpp" // includes glad/glad.h
#include <GLFW/glfw3.h> // must be placed behind glad/glad.h
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include "OBJ.hpp"
using namespace std;







static void mouse_button_callback
(GLFWwindow* window
	, int button
	, int action
	, int mods
)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT
		&& action == GLFW_PRESS)
	{
		double xpos, ypos;
		int width, height;
		glfwGetCursorPos(window, &xpos, &ypos);
		glfwGetWindowSize(window, &width, &height);

		float x = (float)(2 * xpos / width - 1);
		float y = (float)(2 * (height - ypos) / height - 1);
		
	}
}

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
	

	
	//画一个窗口
	GLFWwindow* window = glfwCreateWindow(640, 640, "Triangles", NULL, NULL);\
	//异常处理
	if (!window)
	{
		glfwTerminate();
		throw std::runtime_error("Failed To Create Window");
	}
	//把当前窗口设为上下文
	glfwMakeContextCurrent(window);
	gladLoadGL();
	if (!gladLoadGL())
	{
		glfwTerminate();
		cout << "GLAD failed to load GL functions\n";
	}
	/*if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		glfwTerminate();
		std::cerr << "GLAD failed to load GL functions\n";
		return -1;
	}*/
	cout << "OpenGL version: " << glGetString(GL_VERSION) << '\n';

	OBJ Model;
	Model.load_obj("C:/Users/Administrator/Desktop/Monkey.obj");
	
	
	//glfwSetMouseButtonCallback(window, mouse_button_callback);
	while (!glfwWindowShouldClose(window)) {
		// render graphics
		glClear(GL_COLOR_BUFFER_BIT);
		Model.draw_obj();
		// refresh screen
		//提交画图Buffer
		glfwSwapBuffers(window);
		//拉取操作系统事件
		glfwPollEvents();
	}
	glfwTerminate();
	
	
	return 0;
}
