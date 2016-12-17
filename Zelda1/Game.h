#pragma once
#include "Window.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Link.h"
#include "StateManager.h"
#include "OverworldStartLocation.h"
#include "Terrain.h"

namespace Global
{
	extern bool _gameIsRunning;

	extern bool up;
	extern bool down;
	extern bool left;
	extern bool right;

	extern int playerSpeed;

	extern 	Window _window;
	extern Renderer _renderer;

	extern Terrain _startingLocation;
	extern std::string _startingLocationBmp;
	extern Sprite* _spriteStartingLocation;
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
	bool CollisionCheck(int parentx, int parenty, int parentsize, int childx, int childy, int childsize);
	void CheckForCollisions();
	void CalculateDeltatime();

	Sprite* CheckForAnimationType(Sprite* animation);
	Sprite* _currentSprite;

	InputManager* _getInput;
	InputManager* _inputManager;

	Sprite* _playerIdleDown;
	Sprite* _playerIdleUp;
	Sprite* _playerIdleLeft;
	Sprite* _playerIdleRight;


private:
	StateManager* _stateManager;

	Link _player;
	Link _TestObject2;

	unsigned int _lastTick;
	float _delta;
};

