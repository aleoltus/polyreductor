#ifndef MATERIAL_FOR_DRAW_MODEL
#define MATERIAL_FOR_DRAW_MODEL

#include "MaterialsLibary.h"
#include "ShaderGLSL.h"
#include <memory>
#include <glm\gtc\type_ptr.hpp>

/*
 *Class for drawing the objec in material from MaterialLibary file.
 *This class use Shader class from MyEngine namespace.
*/

namespace PolyReductor
{
	namespace Renderer
	{
		class MaterialForDrawModel
		{
		public:
			MaterialForDrawModel()
			{
				shader.reset(new MyEngine::Renderer::ShaderGlsl);
				shader->loadVertexShader("./res/shaders/blinPhong.vs");
				shader->loadFragmentShade("./res/shaders/blinPhong.fs");
				shader->attachAllShader();
				shaderProgram = shader->getProgram();
			}

			void setMaterial(MaterialType type = MaterialType::COPPER)
			{
				mat = PolyReductor::Renderer::getMaterial(type);
			}/*Set material type for objecs.*/
			void bindMatrial(const glm::vec3& lightPosition /*the best will be eye position*/, const glm::vec3& eyePosition)
			{
				shader->useShader();
				glUniform3fv(glGetUniformLocation(shaderProgram, "material.ambient"), 1, glm::value_ptr(mat.ambient));
				glUniform3fv(glGetUniformLocation(shaderProgram, "material.diffuse"), 1, glm::value_ptr(mat.diffuse));
				glUniform3fv(glGetUniformLocation(shaderProgram, "material.specular"), 1, glm::value_ptr(mat.specular));
				glUniform1f(glGetUniformLocation(shaderProgram, "material.specular"), mat.shiness*128.0f);/*For blin phong light model shiness must be multiply by 128*/
				glUniform3fv(glGetUniformLocation(shaderProgram, "lightPosition"), 1, glm::value_ptr(lightPosition));
				glUniform3fv(glGetUniformLocation(shaderProgram, "eyePosition"), 1, glm::value_ptr(eyePosition));
			}/*bind material, shaders, uniforms variables... Modre in MaterialForDrawModel.cpp file.*/

			GLint getMaterialProgram() { return shaderProgram; }

			~MaterialForDrawModel() {}
		protected:
		private:
			GLint shaderProgram;
			std::shared_ptr<MyEngine::Renderer::ShaderGlsl> shader;
			Material mat;
		};
	}
}

#endif // !MATERIAL_FOR_DRAW_MODEL
