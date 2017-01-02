#pragma once

#include "IState.h"
#include "Window.h"

class Renderer;
class Sprite;
class Terrain;

class OverworldStartLocation : public IState
{
public:
	void UpdatePlayerArea();
	void Enter();
	void Update(float p_delta);
	void Exit();
	void Draw();
	void TransitionScreen(int direction);
};

