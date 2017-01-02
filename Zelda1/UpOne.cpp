#include "UpOne.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Terrain.h"
#include "ServiceLocator.h"
#include "Window.h"
#include "Game.h"

void UpOne::Enter()
{
}

void UpOne::Update(float p_delta)
{
	UpdatePlayerArea();
}

void UpOne::Exit()
{
}

void UpOne::Draw()
{
	Global::_renderer.DrawSprite(Global::_upOne.GetRect().x, Global::_upOne.GetRect().y, Global::_spriteUpOne);
	Global::_upOne.Render(Global::_renderer);

	Global::_renderer.DrawSprite(Global::_startingLocation.GetRect().x, Global::_startingLocation.GetRect().y, Global::_spriteStartingLocation);
	Global::_startingLocation.Render(Global::_renderer);
}

void UpOne::UpdatePlayerArea()
{
	if (Global::_player.GetRect().y < Global::_startingLocation.GetRect().y)
	{
		TransitionScreen(Global::Directions::upDir);
	}
	if (Global::_player.GetRect().y > Global::_upOne.GetRect().y + 720)
	{
		TransitionScreen(Global::Directions::downDir);
	}
	if (Global::_player.GetRect().x < Global::_startingLocation.GetRect().x)
	{
		TransitionScreen(Global::Directions::leftDir);
	}
	if (Global::_player.GetRect().x > Global::_leftOne.GetRect().x + 1280)
	{
		TransitionScreen(Global::Directions::rightDir);
	}
}

void UpOne::TransitionScreen(int direction)
{
	switch (direction)
	{
	case Global::Directions::downDir:
		if (Global::_upOne.GetRect().y > -720)
		{
			Global::_upOne.Move(0, -3);
			Global::_startingLocation.Move(0, -3);
			Global::_player.Move(0, -2);
		}
		else
		{
			Global::_startingLocation.SetPosition(0, 0);
			Global::_upOne.SetPosition(-720, 0);
			Global::_stateManager->SetState("StartingLocation");
		}
		break;
	default:
		break;
	}
}