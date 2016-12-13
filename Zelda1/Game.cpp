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
				_player{ {100, 100, 50, 50}, Global::playerSpeed, {50, 50, 50, 255} },
				_TestObject2{ {300, 300, 50, 50 }, Global::playerSpeed, { 100, 50, 50, 255 } }
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
	CheckForCollisions();
	UpdatePlayerPosition();

	_renderer.Update();

	_player.Render(_renderer);
	_renderer.CreateSprite("../BMP/croak.bmp", _player.GetRect().x, _player.GetRect().y, _player.GetRect().w, _player.GetRect().h);
	_TestObject2.Render(_renderer);

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

bool Game::CollisionCheck(int parentx, int parenty, int parentsize, int childx, int childy, int childsize) //Only takes one size. (Squares only)
{
	if (parentx - parentsize / 2 < childx + childsize / 2 &&
		parentx + parentsize / 2 > childx - childsize / 2 &&
		parenty - parentsize / 2 < childy + childsize / 2 &&
		parenty + parentsize / 2 > childy - childsize / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::CheckForCollisions()
{
	if (CollisionCheck(_player.GetRect().x, _player.GetRect().y, 50, _TestObject2.GetRect().x, _TestObject2.GetRect().y, 50))
	{
		std::cout << "Is Colliding" << std::endl;
	}
}

Game::~Game()
{
}