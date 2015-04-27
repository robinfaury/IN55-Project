#include "GraphicEngine.h"


GraphicEngine::GraphicEngine(int heightWindow, int widthWindow)
{
	this->globalInformation.setSizeWindow(heightWindow, widthWindow);
}

void GraphicEngine::loadShader()
{
	this->shaders["Basic"] = new Shader("../IN55-Project/res/shaders/basic.vert", "../IN55-Project/res/shaders/basic.frag");
	this->shaders["Particle"] = new Shader("../IN55-Project/res/shaders/particle.vert", "../IN55-Project/res/shaders/particle.frag");
	this->shaders["Water"] = new Shader("../IN55-Project/res/shaders/water.vert", "../IN55-Project/res/shaders/water.frag");
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
	this->materials["White"] = new Material(this->shaders["Basic"], "Basic");
	this->materials["Particle"] = new Material(this->shaders["Particle"], "Particle");
	this->materials["Water"] = new Material(this->shaders["Water"], "Water");
}

void GraphicEngine::loadGeometry()
{
	this->geometry["Dragon"] = new Mesh("Dragon");
	this->objLoader.loadOBJ("../IN55-Project/res/meshs/dragonSD.obj", static_cast<Mesh*>(this->geometry["Dragon"]));
	static_cast<Mesh*>(this->geometry["Dragon"])->loadOnGraphicCard();

	this->geometry["Box"] = new Mesh("Box");
	this->objLoader.loadOBJ("../IN55-Project/res/meshs/box.obj", static_cast<Mesh*>(this->geometry["Box"]));
	static_cast<Mesh*>(this->geometry["Box"])->loadOnGraphicCard();

	this->geometry["Plan"] = new Plan("Plan");
	static_cast<Plan*>(this->geometry["Plan"])->loadOnGraphicCard();
}

void GraphicEngine::loadObject3D()
{
	loadCamera();

	this->objects3D["Dragon"] = new GraphicObject3D(&this->globalInformation, "Dragon");
	this->objects3D["Dragon"]->setCurrentGeometry(this->geometry["Dragon"]);
	this->objects3D["Dragon"]->addGraphicRendererComponant(this->materials["Basic"]);
	this->objects3D["Dragon"]->scale(0.05f, 0.05f, 0.05f);
	this->objects3D["Dragon"]->rotate(30, 1.0f, 0.0f, 0.0f);
	this->objects3D["Dragon"]->translate(1.0f, -1.0f, 1.0f);
	this->objects3D["Dragon2"] = new GraphicObject3D(&this->globalInformation, "Dragon2");
	this->objects3D["Dragon2"]->setCurrentGeometry(this->geometry["Dragon"]);
	this->objects3D["Dragon2"]->addGraphicRendererComponant(this->materials["Basic"]);
	this->objects3D["Dragon2"]->scale(0.1f, 0.1f, 0.1f);
	this->objects3D["Dragon2"]->translate(0.0f, 2.0f, 2.0f);

	this->objects3D["Box1"] = new GraphicObject3D(&this->globalInformation, "Box");
	this->objects3D["Box1"]->setCurrentGeometry(this->geometry["Box"]);
	this->objects3D["Box1"]->translate(3.0f, 0.0f, 0.0f);
	//this->objects3D["Box1"]->addGraphicRendererComponant(this->materials["White"]);

	this->objects3D["Plan"] = new GraphicObject3D(&this->globalInformation, "Plan");
	this->objects3D["Plan"]->setCurrentGeometry(this->geometry["Plan"]);
	this->objects3D["Plan"]->addGraphicRendererComponant(this->materials["White"]);
	this->objects3D["Plan"]->translate(0.0f, -0.8f, 0.0f);
	this->objects3D["Plan"]->scale(0.1f, 0.1f, 0.1f);
	ParticleSystem* ps = this->objects3D["Plan"]->addParticleSystemComponant(1000, this->materials["Particle"], false);
	ps->generate(this->objects3D["Plan"], 100);
}

void GraphicEngine::loadCamera()
{
	this->cameras["MainCamera"] = new Camera("MainCamera");
	this->globalInformation.setCurrentCamera(this->cameras["MainCamera"]);
	this->cameras["MainCamera"]->translate(4.0f, -0.5f, 0.0f);
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
	this->cameras["MainCamera"]->update();
	for (std::map<std::string, GraphicObject3D*>::iterator currentObject3D = this->objects3D.begin(); currentObject3D != this->objects3D.end(); ++currentObject3D)
		currentObject3D->second->update();
}

GraphicEngine::~GraphicEngine()
{
	
}