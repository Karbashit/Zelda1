#include "InputManager.h"

InputManager::InputManager()
{

}

void InputManager::KeyBoardInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
		{
			Global::_gameIsRunning = false;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			OnKeyEvent(event.key.keysym.sym, true);
		}
		else if (event.type == SDL_KEYUP)
		{
			OnKeyEvent(event.key.keysym.sym, false);
		}
	}
}

void InputManager::OnKeyEvent(const SDL_Keycode & key, bool isDown)
{
	switch (key)
	{
	case SDLK_ESCAPE:
		Global::_gameIsRunning = false;
		break;
	case SDLK_w:
		Global::up = isDown;
		break;
	case SDLK_s:
		Global::down = isDown;
		break;
	case SDLK_d:
		Global::right = isDown;
		break;
	case SDLK_a:
		Global::left = isDown;
		break;
	default:
		break;
	}

}


InputManager::~InputManager()
{
}