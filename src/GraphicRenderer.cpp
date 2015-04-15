#include "GraphicRenderer.h"

GraphicRenderer::GraphicRenderer() : Componant()
{

}

GraphicRenderer::GraphicRenderer(GlobalInformation* globalInformation) : Componant()
{
	this->globalInformation = globalInformation;
}

void GraphicRenderer::apply()
{
	GLuint programID = this->material->getShader()->getProgramID();
	glUseProgram(programID);
		glUniformMatrix4fv(glGetUniformLocation(programID, "Model"), 1, GL_FALSE, &(*this->globalInformation->getModel())[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "View"), 1, GL_FALSE, &(*this->globalInformation->getView())[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "Projection"), 1, GL_FALSE, &(*this->globalInformation->getProjection())[0][0]);
		glm::vec3* posCam = this->globalInformation->getCameraPosition();
		glUniform3f(glGetUniformLocation(programID, "PosCamera"), posCam->x, posCam->y, posCam->z);
		glUniform3f(glGetUniformLocation(programID, "PosLamp01"), 4.0f, 2.0f, 4.0f);
		glUniform3f(glGetUniformLocation(programID, "ObjectPosition"), 0, 0, 0);
		glUniform3f(glGetUniformLocation(programID, "ObjectScale"), 1, 1, 1);
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
