#pragma once
#include "Window.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Config.h"

	extern bool _gameIsRunning;



class InputManager;

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Update();

	InputManager* getInput;
	InputManager* _inputManager;
private:
	Window _window;
	Renderer _renderer;

};

