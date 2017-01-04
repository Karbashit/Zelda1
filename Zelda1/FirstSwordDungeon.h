#pragma once

#include "IState.h"
#include "Window.h"

class Renderer;
class Sprite;
class Terrain;

class FirstSwordDungeon : public IState
{
public:
	void UpdatePlayerArea();
	void Enter();
	void Update(float p_delta);
	void Exit();
	void Draw();
	bool AquireSword(int parentx, int parenty, int parentsize, int childx, int childy, int childsize);
};

