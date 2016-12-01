#ifndef WINDOW_GLFW_H
#define WINDOW_GLFW_H

#include "Window.h"
#include "OpenGLLibaries.h"
#include <iostream>

namespace MyEngine
{
	namespace Device
	{
		class WindowGlfw:public Window
		{
		public:
			//WindowGlfw(const std::string& name);
			//WindowGlfw(const std::string& name, int flags);
			WindowGlfw(const std::string& name, int width, int height)
			{
				setName(name);
				setWidth(width);
				setHeight(height);
				try
				{
					initializeGlfw();
					createWindow();
				}
				catch (std::string e)
				{
					std::cout << e << "\n";
					throw "Problem in WindowGlfw class!";
				}
			}
			virtual ~WindowGlfw()
			{
				if (window != nullptr)
					glfwDestroyWindow(window);
			}
		public:
			virtual bool MyEngine::Device::WindowGlfw::isClosed()
			{
				return glfwWindowShouldClose(window);
			}

			virtual void MyEngine::Device::WindowGlfw::swapBuffer()
			{
				glfwSwapBuffers(window);
			}

			virtual GLFWwindow * MyEngine::Device::WindowGlfw::getWindow()
			{
				return window;
			}

			virtual void MyEngine::Device::WindowGlfw::waitForEvent()
			{
				//glfwWaitEvents();
				glfwPollEvents();
			}

			virtual void MyEngine::Device::WindowGlfw::initViewport()
			{
				glEnable(GL_DEPTH_TEST);
				glViewport(0, 0, width, height);
			}

			virtual void MyEngine::Device::WindowGlfw::clearWindow(float r, float g, float b, float a)
			{
				glClearColor(r, g, b, a);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			}

			virtual void MyEngine::Device::WindowGlfw::updateWindow()
			{
				glfwGetFramebufferSize(window, &width, &height);
				glViewport(0, 0, width, height);
			}

			virtual void MyEngine::Device::WindowGlfw::createWindow()
			{
				window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
				if (window == NULL)
					throw "Can not create window";
				glfwMakeContextCurrent(window);
			}

			virtual void MyEngine::Device::WindowGlfw::initializeGlfw()
			{
				if (glfwInit())
				{
					glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
					glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
					glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
					glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
				}
				else
					throw "Can not initialize glfw";
			}

		private:
			GLFWwindow* window;

		protected:
//			virtual void createWindow() override;

		private:
	//		void initializeGlfw();
		};

	}
}

#endif // !WINDOW_GLFW_H
