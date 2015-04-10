#include <iostream>

#include "Engine.h"

int main(int argc, char* argv[])
{
	srand (static_cast <unsigned> (time(0)));

	Engine engine;

	engine.setOpenGLParametters(8, 24, 3, 3, 8);
	engine.init(800, 600, "IN55 - Project");
	engine.run();

	return 0;
}