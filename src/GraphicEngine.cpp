#include "GraphicEngine.h"


GraphicEngine::GraphicEngine(int heightWindow, int widthWindow)
{
	this->globalInformation.setSizeWindow(heightWindow, widthWindow);
}

void GraphicEngine::loadShader()
{
	this->shaders["Basic"] = new Shader("../IN55-Project/res/shaders/basic.vert", "", "../IN55-Project/res/shaders/basic.frag");
	this->shaders["Particle"] = new Shader("../IN55-Project/res/shaders/particle.vert", "../IN55-Project/res/shaders/particle.geo", "../IN55-Project/res/shaders/particle.frag");
	this->shaders["ParticleFountainUpdate"] = new Shader("../IN55-Project/res/shaders/particles_update.vert", "../IN55-Project/res/shaders/particles_update.geo", "../IN55-Project/res/shaders/particles_update.frag");
	this->shaders["ParticleFountainRender"] = new Shader("../IN55-Project/res/shaders/particles_render.vert", "../IN55-Project/res/shaders/particles_render.geo", "../IN55-Project/res/shaders/particles_render.frag");
	this->shaders["ParticleExplosionUpdate"] = new Shader("../IN55-Project/res/shaders/particles_update.vert", "../IN55-Project/res/shaders/particles_update_explosion.geo", "../IN55-Project/res/shaders/particles_update.frag");
	this->shaders["ParticleExplosionRender"] = new Shader("../IN55-Project/res/shaders/particles_render.vert", "../IN55-Project/res/shaders/particles_render.geo", "../IN55-Project/res/shaders/particles_render.frag");
	this->shaders["ParticleRainUpdate"] = new Shader("../IN55-Project/res/shaders/particles_update.vert", "../IN55-Project/res/shaders/particles_update_rain.geo", "../IN55-Project/res/shaders/particles_update.frag");
	this->shaders["ParticleRainRender"] = new Shader("../IN55-Project/res/shaders/particles_render.vert", "../IN55-Project/res/shaders/particles_render.geo", "../IN55-Project/res/shaders/particles_render_rain.frag");
	this->shaders["ParticleFireworkUpdate"] = new Shader("../IN55-Project/res/shaders/particles_update.vert", "../IN55-Project/res/shaders/particles_update_firework.geo", "../IN55-Project/res/shaders/particles_update.frag");
	this->shaders["ParticleFireworkRender"] = new Shader("../IN55-Project/res/shaders/particles_render.vert", "../IN55-Project/res/shaders/particles_render.geo", "../IN55-Project/res/shaders/particles_render.frag");
	this->shaders["ParticleFireUpdate"] = new Shader("../IN55-Project/res/shaders/particles_update.vert", "../IN55-Project/res/shaders/particles_update_fire.geo", "../IN55-Project/res/shaders/particles_update.frag");
	this->shaders["ParticleFireRender"] = new Shader("../IN55-Project/res/shaders/particles_render.vert", "../IN55-Project/res/shaders/particles_render.geo", "../IN55-Project/res/shaders/particles_render.frag");
	this->shaders["ParticleEngineUpdate"] = new Shader("../IN55-Project/res/shaders/particles_update.vert", "../IN55-Project/res/shaders/particles_update_engine.geo", "../IN55-Project/res/shaders/particles_update.frag");
	this->shaders["ParticleEngineRender"] = new Shader("../IN55-Project/res/shaders/particles_render.vert", "../IN55-Project/res/shaders/particles_render.geo", "../IN55-Project/res/shaders/particles_render_engine.frag");
	this->shaders["ParticleGravityUpdate"] = new Shader("../IN55-Project/res/shaders/particles_update.vert", "../IN55-Project/res/shaders/particles_update_gravity.geo", "../IN55-Project/res/shaders/particles_update.frag");
	this->shaders["ParticleGravityRender"] = new Shader("../IN55-Project/res/shaders/particles_render.vert", "../IN55-Project/res/shaders/particles_render.geo", "../IN55-Project/res/shaders/particles_render.frag");
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

	this->geometry["Explosion"] = new Mesh("Explosion");
	this->objLoader.loadOBJ("../IN55-Project/res/meshs/explosion.obj", static_cast<Mesh*>(this->geometry["Explosion"]));
	static_cast<Mesh*>(this->geometry["Explosion"])->loadOnGraphicCard();

	this->geometry["Rain"] = new Mesh("Rain");
	this->objLoader.loadOBJ("../IN55-Project/res/meshs/rain.obj", static_cast<Mesh*>(this->geometry["Rain"]));
	static_cast<Mesh*>(this->geometry["Rain"])->loadOnGraphicCard();

	this->geometry["Parapluit"] = new Mesh("Parapluit");
	this->objLoader.loadOBJ("../IN55-Project/res/meshs/parapluit.obj", static_cast<Mesh*>(this->geometry["Parapluit"]));
	static_cast<Mesh*>(this->geometry["Parapluit"])->loadOnGraphicCard();

	this->geometry["Firework"] = new Mesh("Firework");
	this->objLoader.loadOBJ("../IN55-Project/res/meshs/firework.obj", static_cast<Mesh*>(this->geometry["Firework"]));
	static_cast<Mesh*>(this->geometry["Firework"])->loadOnGraphicCard();

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
	this->objects3D["Fountain"]->translate(-5.0f, 1.2f, 10.0f);
	this->objects3D["Fountain"]->rotate(3.14159265359f/2.0f, 0.0f, 1.0f, 0.0f);
	this->objects3D["Fountain"]->scale(0.7f, 0.7f, 0.7f);

	this->objects3D["Explosion"] = new GraphicObject3D(&this->globalInformation, "Explosion");
	this->objects3D["Explosion"]->setCurrentGeometry(this->geometry["Explosion"]);
	this->objects3D["Explosion"]->addGraphicRendererComponant(this->materials["Black"]);
	this->objects3D["Explosion"]->translate(-5.0f, 1.2f, 5.0f);
	this->objects3D["Explosion"]->rotate(3.14159265359f/2.0f, 0.0f, 1.0f, 0.0f);
	this->objects3D["Explosion"]->scale(0.7f, 0.7f, 0.7f);

	this->objects3D["Rain"] = new GraphicObject3D(&this->globalInformation, "Rain");
	this->objects3D["Rain"]->setCurrentGeometry(this->geometry["Rain"]);
	this->objects3D["Rain"]->addGraphicRendererComponant(this->materials["Black"]);
	this->objects3D["Rain"]->translate(-5.0f, 1.2f, 0.0f);
	this->objects3D["Rain"]->rotate(3.14159265359f/2.0f, 0.0f, 1.0f, 0.0f);
	this->objects3D["Rain"]->scale(0.7f, 0.7f, 0.7f);

	this->objects3D["Parapluit"] = new GraphicObject3D(&this->globalInformation, "Parapluit");
	this->objects3D["Parapluit"]->setCurrentGeometry(this->geometry["Parapluit"]);
	this->objects3D["Parapluit"]->addGraphicRendererComponant(this->materials["Black"]);
	this->objects3D["Parapluit"]->translate(-6.0f, 1.6f, -0.05f);
	this->objects3D["Parapluit"]->rotate(3.14159265359f/2.0f, 0.0f, 1.0f, 0.0f);
	this->objects3D["Parapluit"]->scale(0.11f, 0.1f, 0.1f);

	this->objects3D["Firework"] = new GraphicObject3D(&this->globalInformation, "Firework");
	this->objects3D["Firework"]->setCurrentGeometry(this->geometry["Firework"]);
	this->objects3D["Firework"]->addGraphicRendererComponant(this->materials["Black"]);
	this->objects3D["Firework"]->translate(-5.0f, 1.2f, -6.0f);
	this->objects3D["Firework"]->rotate(3.14159265359f/2.0f, 0.0f, 1.0f, 0.0f);
	this->objects3D["Firework"]->scale(0.7f, 0.7f, 0.7f);

	this->objects3DWithParticleSystem["Plan"] = new GraphicObject3D(&this->globalInformation, "Plan");
	this->objects3DWithParticleSystem["Plan"]->setCurrentGeometry(this->geometry["Plan"]);
	this->objects3DWithParticleSystem["Plan"]->translate(-6.0f, 1.0f, 10.0f);
	this->objects3DWithParticleSystem["Plan"]->scale(0.5f, 0.5f, 0.5f);
	ParticleSystemTransformFeedback* ps = this->objects3DWithParticleSystem["Plan"]->addParticleSystemTransformFeedbackComponant();
	ps->setGenPosition(this->objects3DWithParticleSystem["Plan"]->getPostion());
	ps->initializeParticleSystem(this->shaders["ParticleFountainUpdate"], this->shaders["ParticleFountainRender"]);

	this->objects3DWithParticleSystem["Plan2"] = new GraphicObject3D(&this->globalInformation, "Plan2");
	this->objects3DWithParticleSystem["Plan2"]->setCurrentGeometry(this->geometry["Plan"]);
	this->objects3DWithParticleSystem["Plan2"]->translate(-6.0f, 3.0f, 5.0f);
	this->objects3DWithParticleSystem["Plan2"]->scale(0.5f, 0.5f, 0.5f);
	for (int i=0; i<10; ++i)
	{
		ps = this->objects3DWithParticleSystem["Plan2"]->addParticleSystemTransformFeedbackComponant();
		ps->setGeneratorProperty(this->objects3DWithParticleSystem["Plan2"]->getPostion(), glm::vec3(-0.2, -0.2, -0.2), glm::vec3(0.2, 0.2, 0.2), glm::vec3(0.0, 0.0, 0.0), 
								  glm::vec3(0.0f, 0.0f, 0.0f), 1000, 1200, 0.05, 3000, 500);
		ps->initializeParticleSystem(this->shaders["ParticleExplosionUpdate"], this->shaders["ParticleExplosionRender"]);
	}

	this->objects3DWithParticleSystem["Plan3"] = new GraphicObject3D(&this->globalInformation, "Plan3");
	this->objects3DWithParticleSystem["Plan3"]->setCurrentGeometry(this->geometry["Plan"]);
	this->objects3DWithParticleSystem["Plan3"]->translate(-6.0f, 5.0f, -1.0f);
	this->objects3DWithParticleSystem["Plan3"]->scale(0.5f, 0.5f, 0.5f);
	for (int i=0; i<3; ++i)
	{
		ps = this->objects3DWithParticleSystem["Plan3"]->addParticleSystemTransformFeedbackComponant();
		ps->setGeneratorProperty(this->objects3DWithParticleSystem["Plan3"]->getPostion()+glm::vec3(0.0f, 0.0f, 0.051f*12*i), glm::vec3(-0.002, 0.00, -0.002), glm::vec3(0.002, 0.02, 0.002), glm::vec3(0.0, -0.001, 0.0), 
								  glm::vec3(0.0f, 0.1f, 0.3f), 3300, 3300, 0.005f, 30, 25);
		ps->initializeParticleSystem(this->shaders["ParticleRainUpdate"], this->shaders["ParticleRainRender"]);
	}

	this->objects3DWithParticleSystem["Plan4"] = new GraphicObject3D(&this->globalInformation, "Plan4");
	this->objects3DWithParticleSystem["Plan4"]->setCurrentGeometry(this->geometry["Plan"]);
	this->objects3DWithParticleSystem["Plan4"]->translate(-6.0f, 1.0f, -8.0f);
	this->objects3DWithParticleSystem["Plan4"]->scale(0.5f, 0.5f, 0.5f);
	for (int i=0; i<9; ++i)
	{
		ps = this->objects3DWithParticleSystem["Plan4"]->addParticleSystemTransformFeedbackComponant();
		ps->setGeneratorProperty(this->objects3DWithParticleSystem["Plan4"]->getPostion() + glm::vec3(0.0, 0.0, 1.0*(i%3)), glm::vec3(-0.04, 0.3, -0.01*(3-i)), glm::vec3(0.04, 0.4, 0.01*(i)), glm::vec3(0.0, -0.01, 0.0), 
								 glm::vec3(0.0, 0.1, 0.3), 1100, 1200, 0.05, 400, 1);
		ps->initializeParticleSystem(this->shaders["ParticleFireworkUpdate"], this->shaders["ParticleFireworkRender"]);
	}

	this->objects3DWithParticleSystem["Plan5"] = new GraphicObject3D(&this->globalInformation, "Plan5");
	this->objects3DWithParticleSystem["Plan5"]->setCurrentGeometry(this->geometry["Plan"]);
	this->objects3DWithParticleSystem["Plan5"]->translate(6.0f, 1.0f, -8.0f);
	this->objects3DWithParticleSystem["Plan5"]->scale(0.5f, 0.5f, 0.5f);
	ps = this->objects3DWithParticleSystem["Plan5"]->addParticleSystemTransformFeedbackComponant();
	ps->setGeneratorProperty(this->objects3DWithParticleSystem["Plan5"]->getPostion(), glm::vec3(-0.03, 0.0, -0.1), glm::vec3(0.03, 0.0, 0.1), glm::vec3(0.0, 0.0, 0.0), 
								glm::vec3(0.0, 0.1, 0.3), 1100, 1200, 0.08, 30, 10);
	ps->initializeParticleSystem(this->shaders["ParticleFireUpdate"], this->shaders["ParticleFireRender"]);

	this->objects3DWithParticleSystem["Plan6"] = new GraphicObject3D(&this->globalInformation, "Plan6");
	this->objects3DWithParticleSystem["Plan6"]->setCurrentGeometry(this->geometry["Plan"]);
	this->objects3DWithParticleSystem["Plan6"]->translate(6.0f, 1.0f, 0.0f);
	this->objects3DWithParticleSystem["Plan6"]->scale(0.5f, 0.5f, 0.5f);
	ps = this->objects3DWithParticleSystem["Plan6"]->addParticleSystemTransformFeedbackComponant();
	ps->setGeneratorProperty(this->objects3DWithParticleSystem["Plan6"]->getPostion(), glm::vec3(-0.005, 0.01, -0.005), glm::vec3(0.005, 0.05, 0.005), glm::vec3(0.0, 0.0, 0.0), 
								glm::vec3(0.0, 0.1, 0.3), 2100, 2700, 0.1, 30, 1, this->textures["Smoke"]);
	ps->initializeParticleSystem(this->shaders["ParticleEngineUpdate"], this->shaders["ParticleEngineRender"]);

	this->objects3DWithParticleSystem["Plan7"] = new GraphicObject3D(&this->globalInformation, "Plan7");
	this->objects3DWithParticleSystem["Plan7"]->setCurrentGeometry(this->geometry["Plan"]);
	this->objects3DWithParticleSystem["Plan7"]->translate(6.0f, 1.0f, 8.0f);
	this->objects3DWithParticleSystem["Plan7"]->scale(0.5f, 0.5f, 0.5f);
	ps = this->objects3DWithParticleSystem["Plan7"]->addParticleSystemTransformFeedbackComponant();
	ps->setGeneratorProperty(this->objects3DWithParticleSystem["Plan7"]->getPostion(), glm::vec3(-0.005, 0.01, -0.005), glm::vec3(0.005, 0.05, 0.005), glm::vec3(0.0, 0.0, 0.0), 
								glm::vec3(0.0, 0.1, 0.3), 200000, 200000, 0.1, 10000, 85);
	ps->initializeParticleSystem(this->shaders["ParticleGravityUpdate"], this->shaders["ParticleGravityRender"]);
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