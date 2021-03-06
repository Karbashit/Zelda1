#pragma once

#include "IState.h"
#include "Window.h"
#include "BoxCollider.h"

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
	bool CollisionCheck(int parentx, int parenty, int parentsize, int childx, int childy, int childsize);
};

