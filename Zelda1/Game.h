#pragma once
#include "Window.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Config.h"
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

	InputManager* _getInput;
	InputManager* _inputManager;
	Sprite* _playerSprite = nullptr;

private:
	Window _window;
	Renderer _renderer;

	Link _player;

	Link _TestObject2;
};

