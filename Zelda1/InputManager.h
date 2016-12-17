#pragma once
#include "SDLSystem.h"
#include "Game.h"

class Game;

class InputManager 
{
public:
	InputManager();
	~InputManager();
	void KeyBoardInput();
	
	void OnKeyEvent(const SDL_Keycode& key, bool isDown);

private:


};