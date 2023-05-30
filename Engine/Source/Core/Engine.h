#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

namespace Hunter
{
	//we use microsoft specific __declspec(dllexport) to export all the functions inside of this class so that they are visible outside this DLL. 
	//In doing so a .lib file is generated and these exports are stored in that .lib file so that other projects can use it so that these functions are then consumable in those projects/solutions.
	class __declspec(dllexport) Engine
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
}
