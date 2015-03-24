#include "OpenGLWindow.h"

int main(int argc, char* argv[]) 
{
	OpenGLWindow openGLWindow(800, 600, "Project IN55", 8, 24, 3, 3, 8);

	openGLWindow.createWorld();

	openGLWindow.run();

	return EXIT_SUCCESS;
}