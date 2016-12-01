/*
Class for shader program manipulation.
Basicly, one shader program need minimum one vertex file and fragment file.
Rest are optionally.
*/

#ifndef SHADERGLSL_H
#define SHADERGLSL_H

#include "OpenGLLibaries.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace MyEngine
{
	namespace Renderer
	{
		class ShaderGlsl
		{
		public:
			ShaderGlsl()
			{
				program = glCreateProgram();//create shader program
			}
			~ShaderGlsl()
			{
				//clean all shaders and program
				for (auto& x : shaders)
					glDeleteShader(x);
				if (glIsProgram(program))
					glDeleteProgram(program);
			}
			//We won't to have basicly mathematic operation on shader program...
			ShaderGlsl& operator+=(ShaderGlsl&) = delete;
			ShaderGlsl& operator-=(ShaderGlsl&) = delete;
			ShaderGlsl& operator*=(ShaderGlsl&) = delete;
			ShaderGlsl& operator/=(ShaderGlsl&) = delete;
		public:
			/*functions to add source of all parts of shader program*/
			void loadVertexShader(const char* filename)
			{
				GLuint sh = loadShader(filename, GL_VERTEX_SHADER);
				shaders.push_back(sh);
			}
			void loadFragmentShade(const char* filename)
			{
				GLuint sh = loadShader(filename, GL_FRAGMENT_SHADER);
				shaders.push_back(sh);
			}
			void loadGeometryShader(const char* filename)
			{
				shaders.push_back(loadShader(filename, GL_GEOMETRY_SHADER));
			}
			void loadConstrolTesselationShader(const char* filename)
			{
				shaders.push_back(loadShader(filename, GL_TESS_CONTROL_SHADER));
			}

			//after addition of all parts of shader, this parts must be attached to shader program
			void attachAllShader()
			{
				//attach all shaders, link to program and validate this program
				for (auto& x : shaders)
					glAttachShader(program, x);
				linkProgram();
				validateProgram();
			}

			void useShader() { glUseProgram(program); }
			void detachShader() { glUseProgram(0); }
			//return shader program
			GLuint getProgram() { return program; }
		protected:
		private:
			std::string readShader(const char* filename)
			{
				System::Diagnostics::Debug::WriteLine("start load shader");
				
				//read shader from file
				this->filename = filename;
				std::string shadersource;
				std::ifstream file;
				file.open(filename, std::ios::binary);
				if (file.is_open())
				{
					file.seekg(0, file.end);
					shadersource.resize(file.tellg());
					file.seekg(0, file.beg);
					file.read(&shadersource[0], shadersource.size());
					file.close();
				}
				else
				{
					System::Diagnostics::Debug::WriteLine("Cannod load shader");
					std::cerr << "File " << filename << " is not loaded!\n";
				}
				return shadersource;
			}
			void checkShaderError(GLuint& sh)
			{
				//return compilation log, when somthing is wrong
				GLint is_compiled = GL_TRUE;
				glGetShaderiv(sh, GL_COMPILE_STATUS, &is_compiled);
				if (is_compiled == GL_FALSE)
				{
					std::cout << "Shader " << filename << " is not compile!\n";
					GLint loglength{ 0 };
					glGetShaderiv(sh, GL_INFO_LOG_LENGTH, &loglength);
					std::string shaderlog;
					shaderlog.resize(loglength);
					glGetShaderInfoLog(sh, loglength, nullptr, &shaderlog[0]);
					std::cout << shaderlog << "\n";
				}
			}
			GLuint loadShader(const char* filename, GLenum mode)
			{
				//load, compile and get error log, when something is wrong in shader.
				//Use specific enum mode to direct shader type in creating shader function.
				std::string shcourc = readShader(filename);
				const char* shadersource = shcourc.c_str();
				GLuint sh = glCreateShader(mode);
				glShaderSource(sh, 1, &shadersource, nullptr);
				glCompileShader(sh);
				checkShaderError(sh);
				return sh;
			}
			void linkProgram()
			{
				//linkk program after attached all shaders
				glLinkProgram(program);
				GLint islinked;
				glGetProgramiv(program, GL_LINK_STATUS, &islinked);//check that program is linked
				if (islinked == GL_FALSE)
				{
					checkLinkedProgramError();
					return;
				}
				for (auto& x : shaders)
					glDetachShader(program, x);
			}
			void checkLinkedProgramError()
			{
				//return log about linking of program when something is wrong
				GLint length{ 0 };
				glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
				std::string text;
				text.resize(length);
				glGetProgramInfoLog(program, length, nullptr, &text[0]);
				std::cout << "Program is not linked!\n" << text << "\n";
			}
			void validateProgram()
			{
				//validate program with attached shaders and linked program
				glValidateProgram(program);
				checkValidateProgramError();
			}
			void checkValidateProgramError()
			{
				GLint status;
				glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
				if (status == GL_FALSE)
				{
					//if validate had mistakes, get log info and print to console
					std::cout << "Bad validation \n";
					GLint length;
					glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
					char* info = new char[length + 1];
					glGetProgramInfoLog(program, length, nullptr, info);
					std::cout << info << std::endl;
					delete[] info;
				}
			}
		private:
			GLuint program;
			std::string filename;
			std::vector<GLuint> shaders;
		};
	}
}
#endif // !SHADERGLSL_H

