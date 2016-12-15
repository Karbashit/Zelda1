#pragma once
#include "Window.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Link.h"

namespace Global
{
	extern bool _gameIsRunning;

	extern bool up;
	extern bool down;
	extern bool left;
	extern bool right;

	extern int playerSpeed;
}

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

	Sprite* CheckForAnimationType(Sprite* animation);
	Sprite* _currentSprite;

	InputManager* _getInput;
	InputManager* _inputManager;

	Sprite* _playerIdleDown;
	Sprite* _playerIdleUp;
	Sprite* _playerIdleLeft;
	Sprite* _playerIdleRight;


private:
	Window _window;
	Renderer _renderer;

	Link _player;

	Link _TestObject2;
};

