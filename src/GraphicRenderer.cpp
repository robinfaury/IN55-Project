#include "GraphicRenderer.h"

GraphicRenderer::GraphicRenderer() : GraphicComponant()
{

}

GraphicRenderer::GraphicRenderer(Camera* camera) : GraphicComponant()
{
	this->currentCamera = camera;
}

void GraphicRenderer::apply(float time, glm::vec3* position, glm::mat3* rotation, glm::vec3* scale, GlobalInformation* globalInformation)
{
	glm::mat4 model = glm::mat4(*rotation);
	model[3][0] = position->x;
	model[3][1] = position->y;
	model[3][2] = position->z;
	glm::mat4 normalMatrix = glm::inverse(model);
	normalMatrix = glm::transpose(normalMatrix);

	GLuint programID = this->material->getShader()->getProgramID();
	glUseProgram(programID);
		glUniformMatrix4fv(glGetUniformLocation(programID, "Model"), 1, GL_FALSE, &model[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "View"), 1, GL_FALSE, &this->currentCamera->getView()[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "Projection"), 1, GL_FALSE, &this->currentCamera->getProjection()[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "NormalMatrix"), 1, GL_FALSE, &normalMatrix[0][0]);
		
		glUniform3f(glGetUniformLocation(programID, "ObjectScale"), scale->x, scale->y, scale->z);
		
		glm::vec3 posCam = this->currentCamera->getPostion();
		glUniform3f(glGetUniformLocation(programID, "vEyePosition"), posCam.x, posCam.y, posCam.z);
		for (int i=0; i<4; ++i)
		{
			std::string input = "lamp["+std::to_string(i)+"].";
			if (i == 0)
				glUniform3f(glGetUniformLocation(programID, std::string(input+"vPosition").c_str()), 3.0f, 8.0f, 6.0f);
			else if (i == 1)
				glUniform3f(glGetUniformLocation(programID, std::string(input+"vPosition").c_str()), -3.0f, 8.0f, 6.0f);
			else if (i == 2)
				glUniform3f(glGetUniformLocation(programID, std::string(input+"vPosition").c_str()), -3.0f, 8.0f, -6.0f);
			else if (i == 3)
				glUniform3f(glGetUniformLocation(programID, std::string(input+"vPosition").c_str()), 3.0f, 8.0f, -6.0f);
			glUniform3f(glGetUniformLocation(programID, std::string(input+"vColor").c_str()), 1.0f, 1.0f, 1.0f);
			glUniform1f(glGetUniformLocation(programID, std::string(input+"fAmbient").c_str()), 0.15f);
			glUniform1f(glGetUniformLocation(programID, std::string(input+"fConstantAtt").c_str()), 3.0f);
			glUniform1f(glGetUniformLocation(programID, std::string(input+"fLinearAtt").c_str()), 0.1f);
			glUniform1f(glGetUniformLocation(programID, std::string(input+"fExpAtt").c_str()), 0.001f);
		}
		
		if (this->material->getTexture() != NULL)
			glBindTexture(GL_TEXTURE_2D, this->material->getTexture()->getTextureID());
		glUniform1f(glGetUniformLocation(programID, "material.fSpecularIntensity"), 1.0f);
		glUniform1f(glGetUniformLocation(programID, "material.fSpecularPower"), 30.0f);
		glUniform1i(glGetUniformLocation(programID, "isTexture"), (this->material->getTexture() == NULL)? 0 : 1);
		glm::vec3 color = this->material->getColor();
		glUniform3f(glGetUniformLocation(programID, "ObjectColor"), color.x, color.y, color.z);

		this->geometryToDraw->getDrawable()->draw();

		glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}

GraphicRenderer::~GraphicRenderer()
{

}
