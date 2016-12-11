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

	InputManager* _getInput;
	InputManager* _inputManager;
private:
	Window _window;
	Renderer _renderer;
	Link _player;

};

