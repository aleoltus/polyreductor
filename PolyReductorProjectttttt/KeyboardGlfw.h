/*
Implementation of keyboard interface basic on GLFW3 library.
*/

#ifndef KEYBOARD_GLFW_H
#define KEYBOARD_GLFW_H

#include "Keyboard.h"
#include "WindowGlfw.h"
#include <memory>

namespace MyEngine
{
	namespace Device
	{
		class KeyboardGlfw:public MyEngine::Device::Keyboard
		{
		public:
			
			KeyboardGlfw(std::shared_ptr<MyEngine::Device::WindowGlfw> window)
			{
				this->window = window->getWindow();
			}

			virtual MyEngine::Enumerators::KeyboardKeys getKey() override
			{
				if (glfwGetKey(window, GLFW_KEY_A))
					return MyEngine::Enumerators::A_KEY;
				if (glfwGetKey(window, GLFW_KEY_S))
					return MyEngine::Enumerators::S_KEY;
				if (glfwGetKey(window, GLFW_KEY_D))
					return MyEngine::Enumerators::D_KEY;
				if (glfwGetKey(window, GLFW_KEY_W))
					return MyEngine::Enumerators::W_KEY;
				if (glfwGetKey(window, GLFW_KEY_LEFT_ALT))
					return MyEngine::Enumerators::LEFT_ALT_KEY;
				if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL))
					return MyEngine::Enumerators::LEFT_CTRL_KEY;
				if (glfwGetKey(window, GLFW_KEY_ESCAPE))
					return MyEngine::Enumerators::ESCAPE_KEY;
				if (glfwGetKey(window, GLFW_KEY_C))
					return MyEngine::Enumerators::C_KEY;
				if (glfwGetKey(window, GLFW_KEY_ENTER))
					return MyEngine::Enumerators::ENTER_KEY;
				return MyEngine::Enumerators::NO_KEY;
			}

			virtual ~KeyboardGlfw() {}
		private:
			GLFWwindow* window;
		};
	}
}

#endif // !KEYBOARD_GLFW_H
