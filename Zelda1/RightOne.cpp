#include "RightOne.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Terrain.h"
#include "ServiceLocator.h"
#include "Window.h"
#include "Game.h"

void RightOne::Enter()
{
}

void RightOne::Update(float p_delta)
{
	UpdatePlayerArea();
}

void RightOne::Exit()
{
}

void RightOne::Draw()
{
	Global::_renderer.DrawSprite(Global::_rightOne.GetRect().x, Global::_rightOne.GetRect().y, Global::_spriteRightOne);
	Global::_rightOne.Render(Global::_renderer);

	Global::_renderer.DrawSprite(Global::_startingLocation.GetRect().x, Global::_startingLocation.GetRect().y, Global::_spriteStartingLocation);
	Global::_startingLocation.Render(Global::_renderer);
}

void RightOne::UpdatePlayerArea()
{
	if (Global::_player.GetRect().y < Global::_startingLocation.GetRect().y)
	{
		TransitionScreen(Global::Directions::upDir);
	}
	if (Global::_player.GetRect().y > Global::_startingLocation.GetRect().y + 720)
	{
		TransitionScreen(Global::Directions::downDir);
	}
	if (Global::_player.GetRect().x < Global::_rightOne.GetRect().x)
	{
		TransitionScreen(Global::Directions::leftDir);
	}
	if (Global::_player.GetRect().x > Global::_rightOne.GetRect().x + 1280)
	{
		TransitionScreen(Global::Directions::rightDir);
	}
}

void RightOne::TransitionScreen(int direction)
{
	switch (direction)
	{
	case Global::Directions::leftDir:
		if (Global::_rightOne.GetRect().x < 1280)
		{
			Global::_rightOne.Move(3, 0);
			Global::_startingLocation.Move(3, 0);
			Global::_player.Move(2, 0);
		}
		else
		{
			Global::_startingLocation.SetPosition(0, 0);
			Global::_rightOne.SetPosition(1280, 0);
			Global::_stateManager->SetState("StartingLocation");
		}
		break;
	default:
		break;
	}
}