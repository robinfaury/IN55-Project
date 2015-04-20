#include "GraphicRenderer.h"

GraphicRenderer::GraphicRenderer() : GraphicComponant()
{

}

GraphicRenderer::GraphicRenderer(Camera* camera) : GraphicComponant()
{
	this->currentCamera = camera;
}

void GraphicRenderer::apply(glm::vec3 position, glm::mat3 rotation, glm::vec3 scale)
{
	glm::mat4 rotationTranslation = glm::mat4(rotation);
	rotationTranslation[3][0] = position.x;
	rotationTranslation[3][1] = position.y;
	rotationTranslation[3][2] = position.z;

	GLuint programID = this->material->getShader()->getProgramID();
	glUseProgram(programID);
		glUniformMatrix4fv(glGetUniformLocation(programID, "Model"), 1, GL_FALSE, &rotationTranslation[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "View"), 1, GL_FALSE, &this->currentCamera->getView()[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "Projection"), 1, GL_FALSE, &this->currentCamera->getProjection()[0][0]);
		
		glUniform3f(glGetUniformLocation(programID, "ObjectScale"), scale.x, scale.y, scale.z);
		
		glm::vec3 posCam = this->currentCamera->getPostion();
		glUniform3f(glGetUniformLocation(programID, "PosCamera"), posCam.x, posCam.y, posCam.z);
		glUniform3f(glGetUniformLocation(programID, "PosLamp01"), 4.0f, 2.0f, 4.0f);
		
		if (this->material->getTexture() != NULL)
			glBindTexture(GL_TEXTURE_2D, this->material->getTexture()->getTextureID());
		glUniform1i(glGetUniformLocation(programID, "isTexture"), (this->material->getTexture() == NULL)? 0 : 1);
		this->geometryToDraw->getDrawable()->draw();
		glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}

GraphicRenderer::~GraphicRenderer()
{

}
