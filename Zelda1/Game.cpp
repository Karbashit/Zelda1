#include "Game.h"

	bool Global::_gameIsRunning = true;
	bool Global::up		= false;
	bool Global::down	= false;
	bool Global::left	= false;
	bool Global::right	= false;
	int Global::playerSpeed = 1;

Game::Game() :	_window{"Zelda 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720}, 
				_renderer{ _window },
				_inputManager{new InputManager},
				_player{ {100, 100, 50, 50}, Global::playerSpeed, {50, 50, 50, 255} }

{
}

void Game::Run()
{
	while (Global::_gameIsRunning)
	{
		Update();
	}
}

void Game::Update()
{
	UpdatePlayerPosition();

	_renderer.Update();
	_player.Render(_renderer);
	_renderer.Present();

	_getInput->KeyBoardInput();
}

void Game::UpdatePlayerPosition()
{
	if (Global::up)
	{
		_player.Move(0, -Global::playerSpeed);
	}
	if (Global::down)
	{
		_player.Move(0, Global::playerSpeed);
	}
	if (Global::left)
	{
		_player.Move(-Global::playerSpeed, 0);
	}
	if (Global::right)
	{
		_player.Move(Global::playerSpeed, 0);
	}
}

Game::~Game()
{
}