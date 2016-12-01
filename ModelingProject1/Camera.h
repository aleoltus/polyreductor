#ifndef CAMERA_H
#define CAMERA_H

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <iostream>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

/*
Class of camera responsible of good quality of printed models to monitor.
Contain view and perspective matrices.
*/

namespace MyEngine
{
	namespace Renderer
	{
		class Camera
		{
		public:
			/*Constructor. Get:
			pos: position, where camera is.
			target: place, where camera look at
			aspectRatio: aspect of width and heigh of viewport
			FOV: field of view
			zNear: how near some object will be noticed by camera
			zFar: how far some object will be noticed by camera
			UP: up vector to hit the camera.
			*/
			Camera(const glm::vec3& pos, const glm::vec3& target, float aspectRatio, float FOV, float zNear, float zFar, glm::vec3 UP = glm::vec3(0.0f, 1.0f, 0.0f))
			{
				/*set all variables and update view and perspective matrices*/
				this->aspectRatio = aspectRatio;
				this->FOV = glm::radians(FOV);
				this->pos = pos;
				this->up = UP;
				this->zFar = zFar;
				this->zNear = zNear;
				this->target = target;
				updateViewMatrix();
				updatePerspectiveMatrix();
			}
			virtual ~Camera()
			{

			}
			const glm::mat4& getViewMatrix()
			{
				return viewMatrix;//Safty. First update was done in constructor
			}

			const glm::mat4& getProjectionMatrix()
			{
				return _projectionMatrix;//Safty. First update was done in constructor
			}
			const glm::mat4& getViewProjectionMatrix()
			{
				return _projectionMatrix*viewMatrix;//Safty. First update was done in constructor
			}
			void moveForward(float dt)
			{
				pos += target*speed*dt;//update position of camera
			}
			void moveBack(float dt)
			{
				pos -= target*speed*dt;//update position of camera
			}
			void moveLeft(float dt)
			{
				pos -= right*speed*dt;//update position of camera
			}
			void moveRight(float dt)
			{
				pos += right*speed*dt;//update position of camera
			}
			const glm::vec3& getCameraPosition() const
			{
				return pos;
			}
			float getCameraFOV()
			{
				return FOV;
			}
			float getCameraAspectrario()
			{
				return aspectRatio;
			}
			void setAspectRatio(float aspectRatio)
			{
				this->aspectRatio = aspectRatio;
				updatePerspectiveMatrix();
			}
			void setSpeed(float s)
			{
				speed = s;
			}
			void addYaw(float yawOffsed)
			{
				yawOff = yawOffsed;
				yaw += yawOffsed;
				if (yaw > 360.0f || yaw < -360.0f)
					yaw = 0.0f;
			}
			void addPitch(float pithOffsed)
			{
				pitchOff = pithOffsed;
				pith += pithOffsed;
				if (pith > 89.0f)
				{
					pitchOff = 0.0f;
					pith = 89.0f;
				}
				else if (pith < -89.0f)
				{
					pitchOff = 0.0f;
					pith = -89.0f;
				}
			}
			void update()
			{
				//rotate camera using quaterions
				right = glm::normalize(glm::cross(target, glm::vec3(0.0f, 1.0f, 0.0f)));
				glm::quat yawQuat = glm::angleAxis(glm::radians(yawOff), glm::vec3(0.0f, 1.0f, 0.0f));
				glm::quat pitchQuat = glm::angleAxis(glm::radians(pitchOff), right);
				yawOff = 0.0f;
				pitchOff = 0.0f;
				glm::quat rot = glm::normalize(glm::cross(yawQuat, pitchQuat));
				target = glm::normalize(glm::rotate(rot, target));
				up = glm::normalize(glm::cross(right, target));
				updateViewMatrix();
			}

		private:
			glm::mat4 viewMatrix;
			glm::mat4 _projectionMatrix;
			glm::mat4 VP;
			glm::vec3 pos;
			glm::vec3 up;
			glm::vec3 right;
			glm::vec3 target;
			float aspectRatio;
			float FOV;
			float zNear;
			float zFar;
			float speed{ 2.0f };
			float yaw{ 0.0f };
			float pith{ 0.0f };
			float yawOff{ 0.0f }, pitchOff{ 0.0f };
		private:
			void updatePerspectiveMatrix()
			{
				_projectionMatrix = glm::perspective(FOV, aspectRatio, zNear, zFar);
			}
			void updateViewMatrix()
			{
				viewMatrix = glm::lookAt(pos, pos + target, up);
			}
		};
	}
}
#endif //!CAMERA_H
