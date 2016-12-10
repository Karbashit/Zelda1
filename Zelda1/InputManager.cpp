#include "InputManager.h"

InputManager::InputManager()
{

}

void InputManager::KeyBoardInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) == 1)
	{
		if (event.type == SDL_QUIT)
		{
			_gameIsRunning = false;
		}
	}
}


InputManager::~InputManager()
{
}