#include "Engine.h"

int main(int argc, char* argv[])
{
	Engine gameEngine;

	gameEngine.InitializeWindow("Master of Particles", 800, 600, 3, 3, 4, 24, 8);
	gameEngine.init();
	gameEngine.run();

	return 0;
}