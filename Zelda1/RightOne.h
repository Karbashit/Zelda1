#pragma once

#include "IState.h"
#include "Window.h"

class Renderer;
class Sprite;
class Terrain;

class RightOne : public IState
{
public:
	void UpdatePlayerArea();
	void TransitionScreen(int direction);
	void Enter();
	void Update(float p_delta);
	void Exit();
	void Draw();
};

