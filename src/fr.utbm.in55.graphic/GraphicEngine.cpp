#include "GraphicEngine.h"


GraphicEngine::GraphicEngine()
{

}

void GraphicEngine::init()
{
	createWorld();
}

void GraphicEngine::createWorld()
{
	//Shaders
	this->shaders.push_back(new Shader("../IN55-Project/res/shaders/basic.vert", "../IN55-Project/res/shaders/basic.frag"));
	this->shaders.push_back(new Shader("../IN55-Project/res/shaders/picking.vert", "../IN55-Project/res/shaders/picking.frag"));
	this->shaders.push_back(new Shader("../IN55-Project/res/shaders/particle.vert", "../IN55-Project/res/shaders/particle.frag"));

	//Geometry
	this->geometrys.push_back(new Plan());
	this->geometrys.push_back(new Mesh("../IN55-Project/res/meshs/dragonSD.obj", GL_TRIANGLES));

	//Texture
	this->textures.push_back(new Texture("../IN55-Project/res/images/grass.jpg"));
	this->textures.push_back(new Texture("../IN55-Project/res/images/rock.jpg"));

	//Materials
	this->materials.push_back(new Material(this->shaders[0], this->textures[0]));
	this->materials.push_back(new Material(this->shaders[0], this->textures[1]));
	this->materials.push_back(new Material(this->shaders[2]));
	
	//Static Objects
	this->staticObjects.push_back(new PhysicalObject(this->materials[0], this->geometrys[0]));
	this->staticObjects.push_back(new PhysicalObject(this->materials[1], this->geometrys[1]));
	this->staticObjects.push_back(new PhysicalObject(0.0f, 0.2f, 0.0f));
	this->staticObjects[0]->scale(4.0f, 4.0f, 4.0f);
	this->staticObjects[1]->scale(0.2f, 0.2f, 0.2f);
	this->staticObjects[2]->translate(0.0f, 0.0f, 3.0f);

	//Dynamic Objects
	this->dynamicObjects.push_back(new PhysicalObject(this->materials[1], this->geometrys[1]));
	this->dynamicObjects[0]->translate(2.0f, 5.0f, -3.5f);
	this->dynamicObjects[0]->scale(0.2f, 0.2f, 0.2f);

	//ParticleSystems
	this->particleSystems.push_back(new ParticleSystem());
	this->particleSystems[0]->setEmitter(this->staticObjects[2]);
	this->particleSystems[0]->setParticleGeometry(this->geometrys[1]);
	this->particleSystems[0]->setParticleMaterial(this->materials[1]);
	this->particleSystems[0]->setParticleSize(0.01f);
	this->particleSystems[0]->init(1000);

	//Lamps
	this->lamps.push_back(new Lamp(4.3f, 3.0f, 1.0f));

	//Camera
	this->cameras.push_back(new Camera(4.0f, 2.0f, 4.0f));
	this->currentCamera = this->cameras[0];
}

void GraphicEngine::update( float cursorDx,  float cursorDy, std::chrono::system_clock::time_point time)
{
	double radius = 2.0;
	double alpha = 0.0;

	glm::mat4 modelView;
	glm::mat4 projection;
	glm::vec3 posCam = glm::vec3(4, 2 ,4);
	this->projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	this->view       = glm::lookAt(
								posCam,
								glm::vec3(0,0,0),
								glm::vec3(0,1,0)
							);
	this->model      = glm::mat4(1.0f);

	for (std::vector<PhysicalObject*>::iterator staticWorldObject = this->staticObjects.begin(); staticWorldObject != this->staticObjects.end(); ++staticWorldObject)
	{
		if (!(*staticWorldObject)->isVisible())
			continue;
		EnableShader((*staticWorldObject)->getMaterial()->getShader()->getProgramID());
		(*staticWorldObject)->draw();
		DisableShader();
	}
	for (std::vector<PhysicalObject*>::iterator dynamicWorldObject = this->dynamicObjects.begin(); dynamicWorldObject != this->dynamicObjects.end(); ++dynamicWorldObject)
	{
		if (!(*dynamicWorldObject)->isVisible())
			continue;
		EnableShader((*dynamicWorldObject)->getMaterial()->getShader()->getProgramID());
		(*dynamicWorldObject)->draw();
		DisableShader();
	}
	for (std::vector<ParticleSystem*>::iterator particleSystem = this->particleSystems.begin(); particleSystem != this->particleSystems.end(); ++particleSystem)
	{
		(*particleSystem)->update();
		GLuint programID = (*particleSystem)->getParticleMaterial()->getShader()->getProgramID();
		glUseProgram(programID);
			glUniformMatrix4fv(glGetUniformLocation(programID, "Model"), 1, GL_FALSE, &this->model[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(programID, "View"), 1, GL_FALSE, &this->view[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(programID, "Projection"), 1, GL_FALSE, &this->projection[0][0]);
			glUniform3f(glGetUniformLocation(programID, "PosCamera"), 4.0f, 2.0f, 4.0f);
			glUniform3f(glGetUniformLocation(programID, "PosLamp01"), this->lamps[0]->getPosition().x, this->lamps[0]->getPosition().y, this->lamps[0]->getPosition().z);
			(*particleSystem)->draw();
		glUseProgram(0);
	}
}

void GraphicEngine::EnableShader(GLuint programID)
{
	glUseProgram(programID);
		glUniformMatrix4fv(glGetUniformLocation(programID, "Model"), 1, GL_FALSE, &this->model[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "View"), 1, GL_FALSE, &this->view[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(programID, "Projection"), 1, GL_FALSE, &this->projection[0][0]);
		glUniform3f(glGetUniformLocation(programID, "PosCamera"), 4.0f, 2.0f, 4.0f);
		glUniform3f(glGetUniformLocation(programID, "PosLamp01"), this->lamps[0]->getPosition().x, this->lamps[0]->getPosition().y, this->lamps[0]->getPosition().z);
}

void GraphicEngine::DisableShader()
{
	glUseProgram(0);
}

SceneGraph* GraphicEngine::getSceneGraph()
{
    return &this->sceneGraph;
}

GraphicEngine::~GraphicEngine()
{
	for (int i=0; i<this->shaders.size(); ++i)
		delete this->shaders[i];
	for (int i=0; i<this->textures.size(); ++i)
		delete this->textures[i];
	for (int i=0; i<this->materials.size(); ++i)
		delete this->materials[i];
	for (int i=0; i<this->geometrys.size(); ++i)
		delete this->geometrys[i];
	for (int i=0; i<this->staticObjects.size(); ++i)
		delete this->staticObjects[i];
	for (int i=0; i<this->dynamicObjects.size(); ++i)
		delete this->dynamicObjects[i];
	for (int i=0; i<this->lamps.size(); ++i)
		delete this->lamps[i];
	for (int i=0; i<this->cameras.size(); ++i)
		delete this->cameras[i];
}