#include "Game.h"

		int Global::_screenWidth = 1280;
		int Global::_screenHeight = 720;

		bool Global::_gameIsRunning = true;

		bool Global::up		= false;
		bool Global::down	= false;
		bool Global::left	= false;
		bool Global::right	= false;
		bool Global::space = false;
		bool Global::playerFacingDown = false;
		bool Global::playerFacingUp = false;
		bool Global::playerFacingLeft = false;
		bool Global::playerFacingRight = false;

		int Global::swordAquired = 0;

		int Global::playerSpeed = 1;

		Window Global::_window{ "Zelda 1 Clone (Alpha)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Global::_screenWidth, Global::_screenHeight };
		Renderer Global::_renderer{ Global::_window };

		StateManager* Global::_stateManager {new StateManager};

		Link Global::_player{ { 100, 100, 100, 100 }, Global::playerSpeed,{ 50, 50, 50, 255 } };

		BoxCollider Global::_firstSwordDungEntrance{ {300, 50, 50, 50}, {50, 50, 50, 255} };

		Terrain Global::_startingLocation{ {0, 0, 1280, 720}, {0, 0, 0, 255} };
		std::string Global::_startingLocationBmp{"../BMP/Levels/overworld_starting_location.bmp" };
		Sprite* Global::_spriteStartingLocation;

		Terrain Global::_upOne{ {0, 0, 1280, 720}, {0, 0, 0, 255} };
		std::string Global::_upOneBmp{ "../BMP/Levels/overworld_up_one.bmp" };
		Sprite* Global::_spriteUpOne;

		Terrain Global::_leftOne{ { 0, 0, 1280, 720 },{0, 0, 0, 255} };
		std::string Global::_leftOneBmp{ "../BMP/Levels/overworld_left_one.bmp" };
		Sprite* Global::_spriteLeftOne;

		Terrain Global::_rightOne{ { 0, 0, 1280, 720 },{ 0, 0, 0, 255 } };
		std::string Global::_rightOneBmp{ "../BMP/Levels/overworld_right_one.bmp" };
		Sprite* Global::_spriteRightOne;

		Terrain Global::_firstSwordDung{ {0, 0, 1280, 720}, {0, 0, 0, 255} };
		std::string Global::_firstSwordDungBmp{ "../BMP/Levels/dungeon_first_sword.bmp" };
		Sprite* Global::_spriteFirstSwordDung;

		Npc Global::_oldMan{ {0, 0, 100, 100}, {50, 50, 50, 255 } };
		std::string Global::_oldManBmp{ "../BMP/Npcs/old_man.bmp" };
		Sprite* Global::_spriteOldMan;

		Item Global::_masterSword{ { 0, 0, 100, 100 },{ 50, 50, 50, 255 } };
		std::string Global::_masterSwordBmp{ "../BMP/Items/mastersword.bmp" };
		Sprite* Global::_spriteMasterSword;

Game::Game() :
				_inputManager{new InputManager},
				_getInput{ nullptr }
{
	//Player Texture Initialization
	_playerIdleDown = Global::_renderer.CreateSprite("../BMP/Player/link_idle_down.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_playerIdleUp = Global::_renderer.CreateSprite("../BMP/Player/link_idle_up.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_playerIdleRight = Global::_renderer.CreateSprite("../BMP/Player/link_idle_right.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_playerIdleLeft = Global::_renderer.CreateSprite("../BMP/Player/link_idle_left.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_playerAttackDown = Global::_renderer.CreateSprite("../BMP/Player/link_attack_down.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_playerAttackUp = Global::_renderer.CreateSprite("../BMP/Player/link_attack_up.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_playerAttackLeft = Global::_renderer.CreateSprite("../BMP/Player/link_attack_left.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_playerAttackRight = Global::_renderer.CreateSprite("../BMP/Player/link_attack_right.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);
	_currentSprite = Global::_renderer.CreateSprite("../BMP/Player/link_idle_down.bmp", 0, 0, Global::_player.GetRect().w, Global::_player.GetRect().h);

	//Terrain Texture Initialization
	Global::_spriteLeftOne = Global::_renderer.CreateSprite(Global::_leftOneBmp, Global::_leftOne.GetRect().x, Global::_leftOne.GetRect().y,
		Global::_leftOne.GetRect().w, Global::_leftOne.GetRect().h);
	Global::_spriteStartingLocation = Global::_renderer.CreateSprite(Global::_startingLocationBmp, Global::_startingLocation.GetRect().x, Global::_startingLocation.GetRect().y,
		Global::_startingLocation.GetRect().w, Global::_startingLocation.GetRect().h);
	Global::_spriteUpOne = Global::_renderer.CreateSprite(Global::_upOneBmp, Global::_upOne.GetRect().x, Global::_upOne.GetRect().y,
		Global::_upOne.GetRect().w, Global::_upOne.GetRect().h);
	Global::_spriteRightOne = Global::_renderer.CreateSprite(Global::_rightOneBmp, Global::_rightOne.GetRect().x, Global::_rightOne.GetRect().y,
		Global::_rightOne.GetRect().w, Global::_rightOne.GetRect().h);
	Global::_spriteFirstSwordDung = Global::_renderer.CreateSprite(Global::_firstSwordDungBmp, Global::_firstSwordDung.GetRect().x, Global::_firstSwordDung.GetRect().y,
		Global::_firstSwordDung.GetRect().w, Global::_firstSwordDung.GetRect().h);

	//Npcs Texture Initialization
	Global::_spriteOldMan = Global::_renderer.CreateSprite(Global::_oldManBmp, Global::_oldMan.GetRect().x, Global::_oldMan.GetRect().y,
		Global::_oldMan.GetRect().w, Global::_oldMan.GetRect().h);
	//Items Texture Initialization

	Global::_spriteMasterSword = Global::_renderer.CreateSprite(Global::_masterSwordBmp, Global::_masterSword.GetRect().x, Global::_masterSword.GetRect().y,
		Global::_masterSword.GetRect().w, Global::_masterSword.GetRect().h);

}

void Game::Run()
{
	Global::_stateManager->AddState("StartingLocation", new OverworldStartLocation());
	Global::_stateManager->SetState("StartingLocation");

	Global::_stateManager->AddState("UpOne", new UpOne());
	Global::_stateManager->AddState("LeftOne", new LeftOne());
	Global::_stateManager->AddState("RightOne", new RightOne());
	Global::_stateManager->AddState("FirstSwordDungeon", new FirstSwordDungeon());

	while (Global::_gameIsRunning)
	{
		Update();
	}
}

void Game::Update()
{
	UpdatePlayerPosition();

	CheckForAnimationType(_currentSprite);

	_getInput->KeyBoardInput();

	Global::_renderer.Update();

	Global::_stateManager->Update(_delta);
	Global::_stateManager->Draw();

	Global::_renderer.DrawSprite(Global::_player.GetRect().x, Global::_player.GetRect().y, _currentSprite);
	Global::_player.Render(Global::_renderer);

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
	if (Global::space)
	{
		if (Global::playerFacingUp == true)
		{
			_currentSprite = _playerAttackUp;
		}
		if (Global::playerFacingDown == true)
		{
			_currentSprite = _playerAttackDown;
		}
		if (Global::playerFacingLeft == true)
		{
			_currentSprite = _playerAttackLeft;
		}
		if (Global::playerFacingRight == true)
		{
			_currentSprite = _playerAttackRight;
		}
	}
}

Sprite* Game::CheckForAnimationType(Sprite* animation)
{
	if (Global::up)
	{
		_currentSprite = _playerIdleUp;
		Global::playerFacingUp =	true; 
		Global::playerFacingDown =	false; 
		Global::playerFacingLeft =	false; 
		Global::playerFacingRight = false;
	}
			
	if (Global::down)
	{
		_currentSprite = _playerIdleDown;
		Global::playerFacingUp =	false; 
		Global::playerFacingDown =	true; 
		Global::playerFacingLeft =	false; 
		Global::playerFacingRight = false;
	}

	if (Global::left)
	{
		_currentSprite = _playerIdleLeft;
		Global::playerFacingUp =	false; 
		Global::playerFacingDown =	false; 
		Global::playerFacingLeft =	true; 
		Global::playerFacingRight = false;
	}

	if (Global::right)
	{
		_currentSprite = _playerIdleRight;
		Global::playerFacingUp =	false; 
		Global::playerFacingDown =	false; 
		Global::playerFacingLeft =	false; 
		Global::playerFacingRight = true;
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