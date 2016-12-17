#include "Game.h"

int Global::_screenWidth = 1280;
int Global::_screenHeight = 720;

		bool Global::_gameIsRunning = true;
		bool Global::up		= false;
		bool Global::down	= false;
		bool Global::left	= false;
		bool Global::right	= false;
		int Global::playerSpeed = 4;
		Window Global::_window{ "Zelda 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Global::_screenWidth, Global::_screenHeight };
		Renderer Global::_renderer{ Global::_window };
		StateManager* Global::_stateManager {new StateManager};


		Link Global::_player{ { 100, 100, 100, 100 }, Global::playerSpeed,{ 50, 50, 50, 255 } };

		Terrain Global::_startingLocation{ {0, 0, 1280, 720}, {0, 0, 0, 255} };
		std::string Global::_startingLocationBmp{"../BMP/overworld_level_1.bmp" };
		Sprite* Global::_spriteStartingLocation;

		Terrain Global::_upOne{ {0, 0, 1280, 720}, {0, 0, 0, 255} };
		std::string Global::_upOneBmp{ "../BMP/overworld_up_one.bmp" };
		Sprite* Global::_spriteUpOne;

		Terrain Global::_leftOne{ { 0, 0, 1280, 720 },{0, 0, 0, 255} };
		std::string Global::_leftOneBmp{ "../BMP/overworld_left_one.bmp" };
		Sprite* Global::_spriteLeftOne;

		Terrain Global::_rightOne{ { 0, 0, 1280, 720 },{ 0, 0, 0, 255 } };
		std::string Global::_rightOneBmp{ "../BMP/overworld_right_one.bmp" };
		Sprite* Global::_spriteRightOne;

Game::Game() :
				_inputManager{new InputManager},
				_getInput{ nullptr },
				_TestObject2{ {300, 300, 50, 50 }, Global::playerSpeed, { 50, 50, 50, 255 } }
{
	_playerIdleDown = Global::_renderer.CreateSprite("../BMP/link_idle_down.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_playerIdleUp = Global::_renderer.CreateSprite("../BMP/link_idle_up.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_playerIdleRight = Global::_renderer.CreateSprite("../BMP/link_idle_right.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_playerIdleLeft = Global::_renderer.CreateSprite("../BMP/link_idle_left.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_currentSprite = Global::_renderer.CreateSprite("../BMP/link_idle_down.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);

}

void Game::Run()
{
	Global::_stateManager->AddState("StartingLocation", new OverworldStartLocation());
	Global::_stateManager->SetState("StartingLocation");

	Global::_stateManager->AddState("UpOne", new UpOne());
	Global::_stateManager->AddState("LeftOne", new LeftOne());
	Global::_stateManager->AddState("RightOne", new RightOne());

	while (Global::_gameIsRunning)
	{
		Update();
	}
}

void Game::Update()
{
	CheckForCollisions();
	UpdatePlayerPosition();

	CheckForAnimationType(_currentSprite);
	_getInput->KeyBoardInput();

	Global::_renderer.Update();
	Global::_stateManager->Update(_delta);
	
	Global::_stateManager->Draw();
	Global::_renderer.DrawSprite(Global::_player.GetRect().x, Global::_player.GetRect().y, _currentSprite);
	Global::_renderer.FillRect(_TestObject2.GetRect());
	Global::_player.Render(Global::_renderer);
	_TestObject2.Render(Global::_renderer);

	Global::_renderer.Present();
}

void Game::UpdatePlayerPosition()
{
	if (Global::up)
	{
		Global::_player.Move(0, -Global::playerSpeed);
	}
	if (Global::down)
	{
		Global::_player.Move(0, Global::playerSpeed);
	}
	if (Global::left)
	{
		Global::_player.Move(-Global::playerSpeed, 0);
	}
	if (Global::right)
	{
		Global::_player.Move(Global::playerSpeed, 0);
	}
}

bool Game::CollisionCheck(int parentx, int parenty, int parentsize, int childx, int childy, int childsize)
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
	if (CollisionCheck(Global::_player.GetRect().x, Global::_player.GetRect().y, 50, _TestObject2.GetRect().x, _TestObject2.GetRect().y, 50))
	{
		std::cout << "Is Colliding. The collision works with other words." << std::endl;
	}
}

Sprite* Game::CheckForAnimationType(Sprite* animation)
{
	if(Global::up)
	{
			_currentSprite = _playerIdleUp;
	}
	if (Global::down)
	{
			_currentSprite = _playerIdleDown;	
	}
	if (Global::right)
	{
			_currentSprite = _playerIdleRight;
	}
	if (Global::left)
	{
			_currentSprite = _playerIdleLeft;
	}
		return animation;
}

void Game::CalculateDeltatime()
{
	_delta = 0.001f * (SDL_GetTicks() - _lastTick);
	_lastTick = SDL_GetTicks();
}

Game::~Game()
{
}