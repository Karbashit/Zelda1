#include "LeftOne.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Terrain.h"
#include "ServiceLocator.h"
#include "Window.h"
#include "Game.h"

void LeftOne::Enter()
{
}

void LeftOne::Update(float p_delta)
{
	UpdatePlayerArea();
}

void LeftOne::Exit()
{
}

void LeftOne::Draw()
{
	Global::_renderer.DrawSprite(Global::_leftOne.GetRect().x, Global::_leftOne.GetRect().y, Global::_spriteLeftOne);
	Global::_leftOne.Render(Global::_renderer);

	Global::_renderer.DrawSprite(Global::_startingLocation.GetRect().x, Global::_startingLocation.GetRect().y, Global::_spriteStartingLocation);
	Global::_startingLocation.Render(Global::_renderer);
}

void LeftOne::UpdatePlayerArea()
{
	if (Global::_player.GetRect().y < Global::_startingLocation.GetRect().y)
	{
		TransitionScreen(Global::Directions::upDir);
	}
	if (Global::_player.GetRect().y > Global::_startingLocation.GetRect().y + 720)
	{
		TransitionScreen(Global::Directions::downDir);
	}
	if (Global::_player.GetRect().x < Global::_startingLocation.GetRect().w - 1280)
	{
		TransitionScreen(Global::Directions::leftDir);
	}
	if (Global::_player.GetRect().x > Global::_leftOne.GetRect().x + 1280)
	{
		TransitionScreen(Global::Directions::rightDir);
	}
}

void LeftOne::TransitionScreen(int direction)
{
	switch (direction)
	{
	case Global::Directions::rightDir:
		if (Global::_leftOne.GetRect().x > -1280)
		{
			Global::_leftOne.Move(-3, 0);
			Global::_startingLocation.Move(-3, 0);
			Global::_player.Move(-2, 0);
		}
		else
		{
			Global::_startingLocation.SetPosition(0, 0);
			Global::_leftOne.SetPosition(-1280, 0);
			Global::_stateManager->SetState("StartingLocation");
		}
		break;
	default:
		break;
	}
}