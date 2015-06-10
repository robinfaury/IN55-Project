#include "GraphicEngine.h"


GraphicEngine::GraphicEngine(int heightWindow, int widthWindow)
{
	this->globalInformation.setSizeWindow(heightWindow, widthWindow);
}

void GraphicEngine::loadShader()
{
	this->shaders["Basic"] = new Shader("../IN55-Project/res/shaders/basic.vert", "", "../IN55-Project/res/shaders/basic.frag");
	this->shaders["Particle"] = new Shader("../IN55-Project/res/shaders/particle.vert", "../IN55-Project/res/shaders/particle.geo", "../IN55-Project/res/shaders/particle.frag");
}

void GraphicEngine::loadTexture()
{
	this->textures["Grass"] = new Texture("../IN55-Project/res/images/grass.jpg", "Grass");
	this->textures["Rock"] = new Texture("../IN55-Project/res/images/rock.jpg", "Rock");
	this->textures["Smoke"] = new Texture("../IN55-Project/res/images/smoke.jpg", "Smoke");
	this->textures["Room"] = new Texture("../IN55-Project/res/images/room.jpg", "Room");
	this->textures["White"] = new Texture("../IN55-Project/res/images/white.jpg", "White");
}

void GraphicEngine::loadMaterials()
{
	this->materials["Basic"] = new Material("Basic", this->shaders["Basic"]);
	this->materials["Basic"]->setTexture(this->textures["Rock"]);
	this->materials["BasicRoom"] = new Material("BasicRoom", this->shaders["Basic"]);
	this->materials["BasicRoom"]->setTexture(this->textures["Room"]);
	this->materials["White"] = new Material("Basic", this->shaders["Basic"]);
	this->materials["White"]->setTexture(this->textures["White"]);
	this->materials["Black"] = new Material("Basic", this->shaders["Basic"]);
	this->materials["Particle"] = new Material("Particle", this->shaders["Particle"]);
	this->materials["Smoke"] = new Material("Particle", this->shaders["Particle"]);
	this->materials["Smoke"]->setTexture(this->textures["Smoke"]);
	this->materials["Water"] = new Material("Water", this->shaders["Water"]);
}

void GraphicEngine::loadGeometry()
{
	this->geometry["Room"] = new Mesh("Room");
	this->objLoader.loadOBJ("../IN55-Project/res/meshs/room.obj", static_cast<Mesh*>(this->geometry["Room"]));
	static_cast<Mesh*>(this->geometry["Room"])->loadOnGraphicCard();

	this->geometry["Dragon"] = new Mesh("Dragon");
	this->objLoader.loadOBJ("../IN55-Project/res/meshs/dragonSD.obj", static_cast<Mesh*>(this->geometry["Dragon"]));
	static_cast<Mesh*>(this->geometry["Dragon"])->loadOnGraphicCard();

	this->geometry["Box"] = new Mesh("Box");
	this->objLoader.loadOBJ("../IN55-Project/res/meshs/box.obj", static_cast<Mesh*>(this->geometry["Box"]));
	static_cast<Mesh*>(this->geometry["Box"])->loadOnGraphicCard();

	this->geometry["Fountain"] = new Mesh("Fountain");
	this->objLoader.loadOBJ("../IN55-Project/res/meshs/fountain.obj", static_cast<Mesh*>(this->geometry["Fountain"]));
	static_cast<Mesh*>(this->geometry["Fountain"])->loadOnGraphicCard();

	this->geometry["Plan"] = new Plan("Plan");
	static_cast<Plan*>(this->geometry["Plan"])->loadOnGraphicCard();
}

void GraphicEngine::loadObject3D()
{
	loadCamera();

	this->objects3D["Room"] = new GraphicObject3D(&this->globalInformation, "Room");
	this->objects3D["Room"]->setCurrentGeometry(this->geometry["Room"]);
	this->objects3D["Room"]->addGraphicRendererComponant(this->materials["BasicRoom"]);
	this->objects3D["Room"]->translate(0.0f, 1.0f, 0.0f);

	this->objects3D["Dragon"] = new GraphicObject3D(&this->globalInformation, "Dragon");
	this->objects3D["Dragon"]->setCurrentGeometry(this->geometry["Dragon"]);
	//this->objects3D["Dragon"]->addGraphicRendererComponant(this->materials["Basic"]);
	this->objects3D["Dragon"]->scale(0.05f, 0.05f, 0.05f);
	this->objects3D["Dragon"]->rotate(30, 1.0f, 0.0f, 0.0f);
	this->objects3D["Dragon"]->translate(1.0f, -1.0f, 1.0f);
	this->objects3D["Dragon2"] = new GraphicObject3D(&this->globalInformation, "Dragon2");
	this->objects3D["Dragon2"]->setCurrentGeometry(this->geometry["Dragon"]);
	//this->objects3D["Dragon2"]->addGraphicRendererComponant(this->materials["Basic"]);
	this->objects3D["Dragon2"]->scale(0.1f, 0.1f, 0.1f);
	this->objects3D["Dragon2"]->translate(0.0f, 2.0f, 2.0f);

	this->objects3D["Box1"] = new GraphicObject3D(&this->globalInformation, "Box");
	this->objects3D["Box1"]->setCurrentGeometry(this->geometry["Box"]);
	this->objects3D["Box1"]->translate(3.0f, 0.0f, 0.0f);
	//this->objects3D["Box1"]->addGraphicRendererComponant(this->materials["White"]);

	this->objects3D["Fountain"] = new GraphicObject3D(&this->globalInformation, "Fountain");
	this->objects3D["Fountain"]->setCurrentGeometry(this->geometry["Fountain"]);
	this->objects3D["Fountain"]->addGraphicRendererComponant(this->materials["Black"]);
	this->objects3D["Fountain"]->translate(-5.0f, 1.01f, 10.0f);
	this->objects3D["Fountain"]->rotate(3.14159265359f/2.0f, 0.0f, 1.0f, 0.0f);
	this->objects3D["Fountain"]->scale(0.7f, 0.7f, 0.7f);

	this->objects3DWithParticleSystem["Plan"] = new GraphicObject3D(&this->globalInformation, "Plan");
	this->objects3DWithParticleSystem["Plan"]->setCurrentGeometry(this->geometry["Plan"]);
	this->objects3DWithParticleSystem["Plan"]->translate(-6.0f, 1.0f, 10.0f);
	this->objects3DWithParticleSystem["Plan"]->scale(0.5f, 0.5f, 0.5f);
	ParticleSystemTransformFeedback* ps = this->objects3DWithParticleSystem["Plan"]->addParticleSystemTransformFeedbackComponant();
	ps->setGenPosition(this->objects3DWithParticleSystem["Plan"]->getPostion());
	ps->initializeParticleSystem();
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

void GraphicEngine::draw(float time)
{
	this->cameras["MainCamera"]->update();
	for (std::map<std::string, GraphicObject3D*>::iterator currentObject3D = this->objects3D.begin(); currentObject3D != this->objects3D.end(); ++currentObject3D)
		currentObject3D->second->update(time);

	for (std::map<std::string, GraphicObject3D*>::iterator currentObject3D = this->objects3DWithParticleSystem.begin(); currentObject3D != this->objects3DWithParticleSystem.end(); ++currentObject3D)
		currentObject3D->second->update(time);
	
}

GraphicEngine::~GraphicEngine()
{
	
}