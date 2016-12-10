#pragma once
#include "Window.h"
#include "Renderer.h"
#include "InputManager.h"

class InputManager;

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Update();

	bool _gameIsRunning;

	InputManager* getInput;

private:
	Window _window;
	Renderer _renderer;
	InputManager* _inputManager;
};

