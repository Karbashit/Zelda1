#include "Game.h"
#include "SDLSystem.h"
#include "InputManager.h"

int main(int argc, char* argv[])
{
	try
	{
		Game game;
		game.Run();
	}
	catch (const std::runtime_error &error)
	{
		std::cout << error.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Something is wrong." << std::endl;
	}
	return 0;
}