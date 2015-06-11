#include "ParticleSystemTransformFeedback.h"

ParticleSystemTransformFeedback::ParticleSystemTransformFeedback()
{
	this->initialized = false;
	this->first = true;
	this->currentBuffer = 0;
	setGeneratorProperty(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(-0.006f, 0.027f, -0.006f), glm::vec3(0.006f, 0.03f, 0.006f), glm::vec3(0, -0.0003, 0), glm::vec3(0.0f, 0.5f, 1.0f), 3000.0f, 5000.0f, 0.05f, 30, 10);
}

bool ParticleSystemTransformFeedback::initializeParticleSystem(Shader* updateShader, Shader* renderShader)
{
	if (this->initialized)
		return false;

	const char* sVaryings[6] =  
	{ 
		"vertex", 
		"velocity", 
		"color", 
		"life", 
		"size", 
		"type", 
	};

	this->updateShader = updateShader;
	this->renderShader = renderShader;

	glTransformFeedbackVaryings(this->updateShader->getProgramID(), 6, sVaryings, GL_INTERLEAVED_ATTRIBS);
	this->updateShader->linkProgram();

	glGenTransformFeedbacks(1, &this->transformFeedbackBuffer);
	glGenQueries(1, &this->query);

	glGenBuffers(2, this->particleBuffer);
	glGenVertexArrays(2, this->VAO);

	ParticleTransformFeedback particleInitialisation;
	particleInitialisation.iType = 0;
	particleInitialisation.vPosition = this->genPosition;
	particleInitialisation.fSize = this->genSize;
	particleInitialisation.vColor = this->genColor;

	for (int i=0; i<2; ++i)
	{
		glBindVertexArray(this->VAO[i]);
		glBindBuffer(GL_ARRAY_BUFFER, this->particleBuffer[i]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(ParticleTransformFeedback)*500000, NULL, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(ParticleTransformFeedback), &particleInitialisation);

		for (int j=0; j<6; ++j)
			glEnableVertexAttribArray(j);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ParticleTransformFeedback), (const GLvoid*)0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ParticleTransformFeedback), (const GLvoid*)12);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(ParticleTransformFeedback), (const GLvoid*)24);
		glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(ParticleTransformFeedback), (const GLvoid*)36);
		glVertexAttribPointer(4, 1, GL_FLOAT, GL_FALSE, sizeof(ParticleTransformFeedback), (const GLvoid*)40);
		glVertexAttribPointer(5, 1, GL_INT,	  GL_FALSE, sizeof(ParticleTransformFeedback), (const GLvoid*)44);
	}

	this->currentBuffer = 0;
	this->nbParticles = 1;

	this->initialized = true;

	return true;
}

void ParticleSystemTransformFeedback::renderParticles(GlobalInformation* globalInformation)
{
	if (!this->initialized)
		return;

	glDepthMask(0);
	glDisable(GL_RASTERIZER_DISCARD);

	GLuint programID = this->renderShader->getProgramID();
	glUseProgram(programID);
		if (this->texture != NULL)
			glBindTexture(GL_TEXTURE_2D, this->texture->getTextureID());
		glUniformMatrix4fv(glGetUniformLocation(programID, "matrices.mView"), 1, GL_FALSE, &globalInformation->getCurrentCamera()->getView()[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "matrices.mProj"), 1, GL_FALSE, &globalInformation->getCurrentCamera()->getProjection()[0][0]);
		glUniform3f(glGetUniformLocation(programID, "vQuad1"), this->quad1.x, this->quad1.y, this->quad1.z);
		glUniform3f(glGetUniformLocation(programID, "vQuad2"), this->quad2.x, this->quad2.y, this->quad2.z);
		glUniform1f(glGetUniformLocation(programID, "maximumLife"), this->genLifeMin+this->genLifeRange);

		glBindVertexArray(this->VAO[this->currentBuffer]);
		glDisableVertexAttribArray(1);

		glDrawArrays(GL_POINTS, 0,this->nbParticles);

	glUseProgram(0);
	glDepthMask(1);
}

float grandf(float fMin, float fAdd)
{
	float fRandom = float(rand()%(RAND_MAX+1))/float(RAND_MAX);
	return fMin+fAdd*fRandom;
}

void ParticleSystemTransformFeedback::updateParticles(float timePassed)
{
	if (!this->initialized)
		return;

	GLuint programID = this->updateShader->getProgramID();
	glUseProgram(programID);
		glUniform1f(glGetUniformLocation(programID, "timePassed"), timePassed);
		glUniform3f(glGetUniformLocation(programID, "source"), this->genPosition.x, this->genPosition.y, this->genPosition.z);
		glUniform3f(glGetUniformLocation(programID, "minimumVelocity"), this->genVelocityMin.x, this->genVelocityMin.y, this->genVelocityMin.z);
		glUniform3f(glGetUniformLocation(programID, "rangeVelocity"), this->genVelocityRange.x, this->genVelocityRange.y, this->genVelocityRange.z);
		glUniform3f(glGetUniformLocation(programID, "initColor"), this->genColor.x, this->genColor.y, this->genColor.z);
		glUniform3f(glGetUniformLocation(programID, "gravity"), this->genGravity.x, this->genGravity.y, this->genGravity.z);

		glUniform1f(glGetUniformLocation(programID, "minimumLife"), this->genLifeMin);
		glUniform1f(glGetUniformLocation(programID, "rangeLife"), this->genLifeRange);

		glUniform1f(glGetUniformLocation(programID, "initSize"), this->genSize);
		glUniform1i(glGetUniformLocation(programID, "numberNewParticles"), 0);

		glUniform1i(glGetUniformLocation(programID, "first"), this->first);

		this->elapsedTime += timePassed;

		if (this->elapsedTime > this->nextGenerationTime)
		{
			glUniform1i(glGetUniformLocation(programID, "numberNewParticles"), this->nbToGenerate);
			this->elapsedTime = 0;
			glm::vec3 randSpeed = glm::vec3(grandf(-10.0f, 20.0f), grandf(-10.0f, 20.0f), grandf(-10.0f, 20.0f));
			glUniform3f(glGetUniformLocation(programID, "randomSeed"), randSpeed.x, randSpeed.y, randSpeed.z);
		}

		glEnable(GL_RASTERIZER_DISCARD);
		glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, this->transformFeedbackBuffer);

		glBindVertexArray(this->VAO[this->currentBuffer]);
		glEnableVertexAttribArray(1);

		glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, this->particleBuffer[1-this->currentBuffer]);

		glBeginQuery(GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN, this->query);
		glBeginTransformFeedback(GL_POINTS);

		if (first)
			this->first = false;
		glDrawArrays(GL_POINTS, 0, this->nbParticles);

		glEndTransformFeedback();

		glEndQuery(GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN);
		glGetQueryObjectiv(this->query, GL_QUERY_RESULT, &this->nbParticles);

		//std::cout<<this->nbParticles<<std::endl;

		this->currentBuffer = 1 - this->currentBuffer;

		glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0);
	glUseProgram(0);
}

void ParticleSystemTransformFeedback::setGeneratorProperty(glm::vec3 genPosition, glm::vec3 genVelocityMin, glm::vec3 genVelocityMax, glm::vec3 genGravity, glm::vec3 genColor, 
							float genLifeMin, float genLifeMax, float genSize, int every, int numToGenerate, Texture* texture)
{
	this->genPosition = genPosition;
	this->genVelocityMin = genVelocityMin;
	this->genVelocityRange = genVelocityMax - genVelocityMin;
	this->genGravity = genGravity;
	this->genColor = genColor;
	this->genSize = genSize;
	this->genLifeMin = genLifeMin;
	this->genLifeRange = genLifeMax - genLifeMin;
	this->nextGenerationTime = every;
	this->elapsedTime = this->nextGenerationTime;
	this->nbToGenerate = numToGenerate;
	this->texture = texture;
}

void ParticleSystemTransformFeedback::clearAllParticles()
{

}

bool ParticleSystemTransformFeedback::releaseParticleSystem()
{
	return true;
}

void ParticleSystemTransformFeedback::apply(float time, glm::vec3* position, glm::mat3* rotation, glm::vec3* scale, GlobalInformation* globalInformation)
{
	std::cout<<time - this->previousTime<<std::endl;
	this->updateParticles(time - this->previousTime);
	this->previousTime = time;
	glm::vec3 view = globalInformation->getCurrentCamera()->getFocus() - globalInformation->getCurrentCamera()->getPostion();
	view = glm::normalize(view);

	this->quad1 = glm::cross(view, globalInformation->getCurrentCamera()->getUpVector());
	this->quad1 = glm::normalize(this->quad1);
	
	this->quad2 = glm::cross(view, this->quad1);
	this->quad2 = glm::normalize(this->quad2);

	renderParticles(globalInformation);
}

int ParticleSystemTransformFeedback::getNbParticles()
{
	return this->nbParticles;
}

ParticleSystemTransformFeedback::~ParticleSystemTransformFeedback()
{

}
