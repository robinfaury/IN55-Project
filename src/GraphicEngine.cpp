#include "GraphicEngine.h"


GraphicEngine::GraphicEngine()
{
	
}

void GraphicEngine::loadShader()
{
	this->shaders["Basic"] = new Shader("../IN55-Project/res/shaders/basic.vert", "../IN55-Project/res/shaders/basic.frag");
}

void GraphicEngine::loadTexture()
{
	this->textures["Grass"] = new Texture("../IN55-Project/res/images/grass.jpg", "Grass");
}

void GraphicEngine::loadMaterials()
{
	this->materials["Basic"] = new Material(this->shaders["Basic"], "Basic");
	this->materials["Basic"]->setTexture(this->textures["Grass"]);
}

void GraphicEngine::loadGeometry()
{
	this->geometry["Dragon"] = new Mesh("Dragon");
	this->objLoader.loadOBJ("../IN55-Project/res/meshs/dragonSD.obj", static_cast<Mesh*>(this->geometry["Dragon"]));
	static_cast<Mesh*>(this->geometry["Dragon"])->loadOnGraphicCard();
}

void GraphicEngine::loadObject3D()
{
	this->objects3D["Dragon"] = new Object3D(&this->globalInformation, this->geometry["Dragon"], "Dragon");
	this->objects3D["Dragon"]->addGraphicRendererComponant(this->materials["Basic"]);
}

void GraphicEngine::loadLevel()
{
	loadShader();
	loadTexture();
	loadMaterials();
	loadGeometry();
	loadObject3D();
}

void GraphicEngine::draw()
{
	this->globalInformation.setCameraProperty(glm::vec3(4.0f, 2.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	this->globalInformation.computeModelViewProjectionMatrix();

	for (std::map<std::string, Object3D*>::iterator currentObject3D = this->objects3D.begin(); currentObject3D != this->objects3D.end(); ++currentObject3D)
		currentObject3D->second->update();
}

GraphicEngine::~GraphicEngine()
{
	
}