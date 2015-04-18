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
	this->textures["Rock"] = new Texture("../IN55-Project/res/images/rock.jpg", "Rock");
}

void GraphicEngine::loadMaterials()
{
	this->materials["Basic"] = new Material(this->shaders["Basic"], "Basic");
	this->materials["Basic"]->setTexture(this->textures["Rock"]);
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
	this->objects3D["Dragon"]->scale(0.2f, 0.2f, 0.2f);
	this->objects3D["Dragon"]->rotate(30, 1.0f, 0.0f, 0.0f);
	this->objects3D["Dragon"]->translate(1.0f, 0.0f, 0.0f);
	this->objects3D["Dragon2"] = new Object3D(&this->globalInformation, this->geometry["Dragon"], "Dragon");
	this->objects3D["Dragon2"]->addGraphicRendererComponant(this->materials["Basic"]);
	this->objects3D["Dragon2"]->scale(0.2f, 0.2f, 0.2f);
	this->objects3D["Dragon2"]->rotate(30, 1.0f, 0.0f, 0.0f);
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