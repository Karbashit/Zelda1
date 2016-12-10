#include "InputManager.h"

InputManager::InputManager() : getGame{new Game}
{
	getGame->_gameIsRunning = false;
}

void InputManager::KeyBoardInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) !=0)
	{
		if (event.type == SDL_QUIT)
		{
				getGame->_gameIsRunning = false;
		}
	}
}

InputManager::~InputManager()
{
}
