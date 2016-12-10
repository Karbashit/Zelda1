#include "Game.h"

Game::Game() :	_gameIsRunning(true), 
				_window{"Zelda 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600}, 
				_renderer{ _window },
				_inputManager{ new InputManager }
{
}

void Game::Run()
{
	while (_gameIsRunning)
	{
		Update();
	}
}

void Game::Update()
{
	SDL_Rect rect = { 50, 50, 50, 50 };
	SDL_Color color = { 0x20, 0x11, 0x10, 0xFF };
	_renderer.Update();
	_renderer.DrawRect(rect, color);
	_renderer.Present();

	getInput->KeyBoardInput();
}

Game::~Game()
{
}