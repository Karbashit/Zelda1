#pragma once
#include "Window.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Link.h"
#include "StateManager.h"
#include "Terrain.h"
#include "BoxCollider.h"
#include "Npc.h"
#include "Item.h"

#include "OverworldStartLocation.h"
#include "UpOne.h"
#include "LeftOne.h"
#include "RightOne.h"
#include "FirstSwordDungeon.h"

namespace Global
{
	enum Directions
	{
		leftDir = 1,
		upDir = 2,
		rightDir = 3,
		downDir = 4
	};

	extern bool _gameIsRunning;

	extern bool up;
	extern bool down;
	extern bool left;
	extern bool right;
	extern bool space;

	extern bool playerFacingUp;
	extern bool playerFacingDown;
	extern bool playerFacingLeft;
	extern bool playerFacingRight;

	extern int swordAquired;

	extern int playerSpeed;
	extern int _screenWidth;
	extern int _screenHeight;

	extern Link _player;

	extern BoxCollider _firstSwordDungEntrance;

	extern 	Window _window;
	extern Renderer _renderer;
	extern StateManager* _stateManager;

	extern Terrain _startingLocation;
	extern std::string _startingLocationBmp;
	extern Sprite* _spriteStartingLocation;

	extern Terrain _upOne;
	extern std::string _upOneBmp;
	extern Sprite* _spriteUpOne;

	extern Terrain _leftOne;
	extern std::string _leftOneBmp;
	extern Sprite* _spriteLeftOne;

	extern Terrain _rightOne;
	extern std::string _rightOneBmp;
	extern Sprite* _spriteRightOne;

	extern Terrain _firstSwordDung;
	extern std::string _firstSwordDungBmp;
	extern Sprite* _spriteFirstSwordDung;

	extern Npc _oldMan;
	extern std::string _oldManBmp;
	extern Sprite* _spriteOldMan;

	extern Item _masterSword;
	extern std::string _masterSwordBmp;
	extern Sprite* _spriteMasterSword;
}

class StateManager;
class InputManager;

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Update();
	void UpdatePlayerPosition();
	void CalculateDeltatime();

	Sprite* CheckForAnimationType(Sprite* animation);
	Sprite* _currentSprite;

	InputManager* _getInput;
	InputManager* _inputManager;

	Sprite* _playerIdleDown;
	Sprite* _playerIdleUp;
	Sprite* _playerIdleLeft;
	Sprite* _playerIdleRight;
	Sprite* _playerAttackDown;
	Sprite* _playerAttackUp;
	Sprite* _playerAttackLeft;
	Sprite* _playerAttackRight;


private:
	unsigned int _lastTick;
	float _delta;

	int _screenWidth = 1280;
	int _screenHeight = 720;
};

