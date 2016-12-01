#ifndef REDUCE_SYSTEM_H
#define REDUCE_SYSTEM_H

#include <memory>
#include "Window.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "ModelForReduction.h"
#include "MaterialsLibary.h"
#include "OpenGLLibaries.h"
#include <string>
#include <iostream>
#include "WindowGlfw.h"
#include "MouseGlfw.h"
#include "KeyboardGlfw.h"
#include <glm\gtc\type_ptr.hpp>
#include "FPSTicker.h"
#include <opencv2\opencv.hpp>
#include "Camera.h"
#include "Transform.h"
#include "MaterialForDrawModel.h"

namespace PolyReductor
{
	class ReduceSystem
	{
	public:

		void initializeFramework()
		{
			int width{ 400 }, height{ 400 };
			window[0].reset(new MyEngine::Device::WindowGlfw("Poly Reductor (PR)", width, height));
			mouse.reset(new MyEngine::Device::MouseGlfw(std::dynamic_pointer_cast<MyEngine::Device::WindowGlfw>(window[0])));
			keyboard.reset(new MyEngine::Device::KeyboardGlfw(std::dynamic_pointer_cast<MyEngine::Device::WindowGlfw>(window[0])));
			camera.reset(new MyEngine::Renderer::Camera(glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, -1.0f), (float)width / (float)height, 45.0f, 0.1f, 1000.0f));
			
			glewExperimental = GL_TRUE;
			if (glewInit() != GLEW_OK)
			{
				std::string exception = "GLEW isn't initialized!\n";
				throw exception;
			}

			std::string OglVers(std::string("Opengl version ") + std::string((char*)glGetString(GL_VERSION)) + "\n");
			std::cout.write(OglVers.c_str(), OglVers.size());
			std::string OglSLVers(std::string("Opengl version ") + std::string((char*)glGetString(GL_SHADING_LANGUAGE_VERSION)) + "\n");
			std::cout.write(OglSLVers.c_str(), OglVers.size());


			PolyReductor::Renderer::MaterialType mat = PolyReductor::Renderer::MaterialType::COPPER;
			materialForDrawingModell.reset(new PolyReductor::Renderer::MaterialForDrawModel);
			materialForDrawingModell->setMaterial(mat);
			materialForDrawingModell->bindMatrial(camera->getCameraPosition()*10.0f, camera->getCameraPosition());

			transform.reset(new MyEngine::Renderer::Transform);
			transform->setScale(glm::vec3(1.0));
			transform->update();
		}

		void reduce(float percentVertex)
		{
			int restvertex = oldModel->getNumOfVertices()*(percentVertex/100.0f);
			newModel->reduce(restvertex);
		}

		void loadModel(const std::string& fileName)
		{
			oldModel.reset(new PolyReductor::Renderer::ModelForReduction(fileName));
			newModel.reset(new PolyReductor::Renderer::ModelForReduction(fileName));
			transform->setScale(glm::vec3(1.0/oldModel->getScaleFactor().x));
			transform->update();
		}

		void draw()
		{
			window[0]->initViewport();
			bool cloase = false;

			MyEngine::Enumerators::KeyboardKeys keys;
			double fps = 0.1;

			oldModel->prepareModelToDraw();
			newModel->prepareModelToDraw();
			//fpsTicker.start();

			while (!window[0]->isClosed() && !cloase)
			{
				glm::mat4 m = transform->getModelMatrix();
				glm::mat4 v = camera->getViewMatrix();
				glm::mat4 p = camera->getProjectionMatrix();
				window[0]->clearWindow(0.0, 0.0, 0.0, 1.0);
				PolyReductor::Renderer::MaterialType mat = PolyReductor::Renderer::MaterialType::COPPER;

				materialForDrawingModell->setMaterial(mat);
				materialForDrawingModell->bindMatrial(camera->getCameraPosition()*10.0f, camera->getCameraPosition());
				newModel->draw(materialForDrawingModell->getMaterialProgram(), m, v, p);

				keys = keyboard->getKey();
				if (keys == MyEngine::Enumerators::ESCAPE_KEY)
					cloase = true;

				dt = 0.1;// = fpsTicker.getDt();
				if (mouse->getBurtton() == MyEngine::Enumerators::LEFT_BUTTON)
				{
					moveCamera(keys);
					transform->update();
				}
				window[0]->swapBuffer();
				window[0]->waitForEvent();

				/*glReadBuffer(GL_BACK_LEFT);
				glReadPixels(0, 0, width, height, GL_BGR, GL_UNSIGNED_BYTE, buffer);
				cv::Mat image(height, width, CV_8UC3, buffer);

				cv::namedWindow("name");
				cv::imshow("name", image);*/

				window[0]->updateWindow();
				camera->update();
				

				//fpsTicker.getFPSValue();

				//transform->rotate(glm::vec3(dt / 10.0f, 0.0, 0.0));
				//transform->update();
			}
		}

		float compareModels()
		{
			std::shared_ptr<MyEngine::Renderer::Transform> tr(new MyEngine::Renderer::Transform);
			tr->setScale(glm::vec3(1.0));
			tr->update();
			oldModel->prepareModelToDraw();
			newModel->prepareModelToDraw();
			glm::mat4 lookMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0, 1.0f, 0.0));
			glm::mat4 perspectiveMatrix = glm::perspective(glm::radians(45.0f), 1.0f, 0.01f, 1000.0f);
			oldModel->createHistograms(materialForDrawingModell->getMaterialProgram(), tr, camera->getViewMatrix(), camera->getProjectionMatrix(), 400, 400);
			newModel->createHistograms(materialForDrawingModell->getMaterialProgram(), tr, camera->getViewMatrix(), camera->getProjectionMatrix(), 400, 400);
			return compareHistograms(oldModel->getHistograms(), newModel->getHistograms());
		}

		void saveModel(const std::string& fileName)
		{
			newModel->saveModel(fileName);
		}

		glm::ivec2 getMousePosition()
		{
			return std::dynamic_pointer_cast<MyEngine::Device::MouseGlfw>(mouse)->getCursorPosition<glm::ivec2>();
		}

		void mouseMoveCamera()
		{
			glm::ivec2 oldMousePos = getMousePosition();//glm::ivec2(window[0]->getWidth() / 2, window[0]->getHeight() / 2);
			System::Threading::Thread::Sleep(10);
			glm::ivec2 newMousePos = getMousePosition();
			glm::ivec2 delta = oldMousePos - newMousePos;
			transform->rotate(glm::vec3(glm::vec2(-delta.y,-delta.x)/50.0f, 0.0f));
			transform->update();
			//std::dynamic_pointer_cast<MyEngine::Device::MouseGlfw>(mouse)->setCursorPosition<glm::ivec2>(oldMousePos);
		}

		void keyboardMoveCamera(MyEngine::Enumerators::KeyboardKeys keys)
		{
			using namespace MyEngine;
			using namespace Enumerators;
			if (keys == W_KEY)
				camera->moveForward(dt / 10);
			else if (keys == S_KEY)
				camera->moveBack(dt / 10);
			else if (keys == A_KEY)
				camera->moveLeft(dt / 10);
			else if (keys == D_KEY)
				camera->moveRight(dt / 10);
		}

		void moveCamera(MyEngine::Enumerators::KeyboardKeys keys)
		{
			mouseMoveCamera();
			keyboardMoveCamera(keys);
		}

	private:
		std::shared_ptr<MyEngine::Device::Window> window[2];
		std::shared_ptr<MyEngine::Device::Mouse> mouse;
		std::shared_ptr<MyEngine::Device::Keyboard> keyboard;
		std::shared_ptr<PolyReductor::Renderer::ModelForReduction> oldModel;
		std::shared_ptr<PolyReductor::Renderer::ModelForReduction> newModel;
		std::shared_ptr<MyEngine::Renderer::Camera> camera;
		std::shared_ptr<MyEngine::Renderer::Transform> transform;
		std::shared_ptr<PolyReductor::Renderer::MaterialForDrawModel> materialForDrawingModell;
		float dt;
		FPSTicker fpsTicker;
	};
}
#endif // !REDUCE_SYSTEM_H
