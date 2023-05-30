#include "Engine.h"
#include <iostream>

namespace Hunter
{
    Engine::Engine()
    {
    }

    Engine::~Engine()
    {
    }


    const bool& Engine::Init()
    {
        // glfw: initialize and configure
      // ------------------------------
        int value = glfwInit();

        if (value != GLFW_TRUE)
        {
            std::cout << "Failed to init glfwInit" << std::endl;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // glfw window creation
        // --------------------

        Window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Isekai", NULL, NULL);

        if (Window == nullptr)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return false;
        }
        glfwMakeContextCurrent(Window);
        glfwSetFramebufferSizeCallback(Window, Engine::framebuffer_size_callback);

        // glad: load all OpenGL function pointers
       // ---------------------------------------
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return false;
        }

        return true;
    }

    void Engine::Run()
    {
        // render loop
        // -----------
        while (!glfwWindowShouldClose(Window))
        {
            // input
            // -----
            ProcessInput(Window);

            // render
            // ------
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
            // -------------------------------------------------------------------------------
            glfwSwapBuffers(Window);
            glfwPollEvents();
        }

        // glfw: terminate, clearing all previously allocated GLFW resources.
        // ------------------------------------------------------------------
        glfwTerminate();
    }

    void Engine::ProcessInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    void Engine::framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        // make sure the viewport matches the new window dimensions; note that width and 
        // height will be significantly larger than specified on retina displays.
        glViewport(0, 0, width, height);
    }

}
