// Example file, this is normally created by the End User.
// This is where the program actually runs.
//
#include "GoopEngine.hpp"

Goop::GoopEngine* game = nullptr;

int main(int argc, char *argv[])
{
	game = new Goop::GoopEngine();

	game->init("Goop Test", 640, 480);
	
	while (game->isRunning())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->quit();
	return 0;
}
