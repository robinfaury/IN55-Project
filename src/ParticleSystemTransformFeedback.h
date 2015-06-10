#ifndef PARTICLESYSTEMTRANSFORMFEEDBACK_H
#define PARTICLESYSTEMTRANSFORMFEEDBACK_H

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <glm.hpp>

#include "Shader.h"
#include "GraphicComponant.h"

enum PARTICLETYPE
{
	PARTICLE_TYPE_GENERATOR = 0,
	PARTICLE_TYPE_BASIC
};

class ParticleTransformFeedback
{
public:
	glm::vec3 vPosition;
	glm::vec3 vVelocity;
	glm::vec3 vColor;
	float fLifeTime;
	float fSize;
	int iType;
};

class ParticleSystemTransformFeedback : public GraphicComponant
{
private:
	bool initialized;
	bool first;
	GLuint transformFeedbackBuffer;
	GLuint particleBuffer[2];
	GLuint VAO[2];

	GLuint query;
	GLuint texture;

	int currentBuffer;
	int nbParticles;

	glm::vec3 quad1, quad2;

	float previousTime;
	float elapsedTime;
	float nextGenerationTime;

	glm::vec3 genPosition;
	glm::vec3 genVelocityMin, genVelocityRange;
	glm::vec3 genGravity;
	glm::vec3 genColor;
	
	float genLifeMin, genLifeRange;
	float genSize;

	int nbToGenerate;

	Shader* renderShader;
	Shader* updateShader;

public:
	ParticleSystemTransformFeedback();

	bool initializeParticleSystem();

	void renderParticles(GlobalInformation* globalInformation);
	void updateParticles(float timePassed);

	void setGeneratorProperty(glm::vec3 genPosition, glm::vec3 genVelocityMin, glm::vec3 genVelocityMax, glm::vec3 genGravity, glm::vec3 genColor, 
							  float genLifeMin, float genLifeMax, float genSize, float every, int numToGenerate);

	void setGenPosition(glm::vec3 genPosition) {this->genPosition = genPosition;}

	void clearAllParticles();
	bool releaseParticleSystem();

	virtual void apply(float time, glm::vec3* position, glm::mat3* rotation, glm::vec3* scale, GlobalInformation* globalInformation);

	int getNbParticles();

	~ParticleSystemTransformFeedback();
};

#endif 