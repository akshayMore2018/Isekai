#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>


class Engine
{
public:

	Engine();
	~Engine();

	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;

	const bool& Init();

	void Run();


private:

	void ProcessInput(GLFWwindow* window);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	GLFWwindow* Window;


	// settings
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;
};