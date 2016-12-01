#ifndef WINDOW_H
#define WINDOW_H

#include <string>


namespace MyEngine
{
	namespace Device
	{
		class Window
		{
		public:
			Window() {};
			virtual ~Window() {};
			virtual bool isClosed() = 0;
			virtual void swapBuffer() = 0;
			virtual void waitForEvent() = 0;
			virtual void initViewport() = 0;
			virtual void clearWindow(float r, float g, float b, float a) = 0;
			virtual void updateWindow() = 0;
		public:
			std::string MyEngine::Device::Window::getName()
			{
				return name;
			}

			void MyEngine::Device::Window::setName(const std::string & name)
			{
				this->name = name;
			}

			int MyEngine::Device::Window::getWidth()
			{
				return width;
			}

			void MyEngine::Device::Window::setWidth(int width)
			{
				this->width = width;
			}

			int MyEngine::Device::Window::getHeight()
			{
				return height;
			}

			void MyEngine::Device::Window::setHeight(int height)
			{
				this->height = height;
			}
		protected:
			std::string name;
			int width;
			int height;

			virtual void createWindow() = 0;
		private:

		};
	}
}
#endif // !WINDOW_H

