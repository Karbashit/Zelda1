#include "OverworldStartLocation.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Terrain.h"
#include "ServiceLocator.h"
#include "Window.h"
#include "Game.h"

void OverworldStartLocation::Enter()
{
	Global::_startingLocation.SetPosition(0, 0);
	Global::_upOne.SetPosition(0, -720);
	Global::_leftOne.SetPosition(-1280, 0);
	Global::_rightOne.SetPosition(1280, 0);

}

void OverworldStartLocation::Update(float p_delta)
{
	UpdatePlayerArea();
}

void OverworldStartLocation::Exit()
{
}

void OverworldStartLocation::Draw()
{
	Global::_renderer.DrawSprite(Global::_upOne.GetRect().x, Global::_upOne.GetRect().y, Global::_spriteUpOne);
	Global::_upOne.Render(Global::_renderer);

	Global::_renderer.DrawSprite(Global::_startingLocation.GetRect().x, Global::_startingLocation.GetRect().y, Global::_spriteStartingLocation);
	Global::_startingLocation.Render(Global::_renderer);

	Global::_renderer.DrawSprite(Global::_rightOne.GetRect().x, Global::_rightOne.GetRect().y, Global::_spriteRightOne);
	Global::_rightOne.Render(Global::_renderer);

	Global::_renderer.DrawSprite(Global::_leftOne.GetRect().x, Global::_leftOne.GetRect().y, Global::_spriteLeftOne);
	Global::_leftOne.Render(Global::_renderer);
}

void OverworldStartLocation::UpdatePlayerArea()
{
	if (Global::_player.GetRect().y < Global::_startingLocation.GetRect().y)
	{
		TransitionScreen(Global::Directions::upDir);
	}
	if (Global::_player.GetRect().y > Global::_startingLocation.GetRect().y)
	{
	}
	if (Global::_player.GetRect().x < Global::_startingLocation.GetRect().x)
	{
		TransitionScreen(Global::Directions::leftDir);
	}
	if (Global::_player.GetRect().x > Global::_startingLocation.GetRect().x + 1280)
	{
		TransitionScreen(Global::Directions::rightDir);
	}
	if(CollisionCheck(Global::_player.GetRect().x, Global::_player.GetRect().y, 100, Global::_firstSwordDungEntrance.GetRect().x, Global::_firstSwordDungEntrance.GetRect().y, 50))
	{
		Global::_stateManager->SetState("FirstSwordDungeon");
		Global::_player.GetPos(600, 570);
	}
}

void OverworldStartLocation::TransitionScreen(int direction)
{
	switch (direction)
	{
	case Global::Directions::leftDir:
		if (Global::_startingLocation.GetRect().x < 1280)
		{
			Global::_leftOne.Move(3, 0);
			Global::_startingLocation.Move(3, 0);
			Global::_player.Move(2, 0);
		}
		else
		{
			Global::_leftOne.SetPosition(0, 0);
			Global::_startingLocation.SetPosition(1280, 0);
			Global::_stateManager->SetState("LeftOne");
		}
		break;
	case Global::Directions::rightDir:
		if (Global::_startingLocation.GetRect().x > -1280)
		{
			Global::_rightOne.Move(-3, 0);
			Global::_startingLocation.Move(-3, 0);
			Global::_player.Move(-2, 0);
		}
		else
		{
			Global::_startingLocation.SetPosition(-1280, 0);
			Global::_rightOne.SetPosition(0, 0);
			Global::_stateManager->SetState("RightOne");
		}
		break;
	case Global::Directions::upDir:
		if (Global::_startingLocation.GetRect().y < 720)
		{
			Global::_upOne.Move(0, 3);
			Global::_startingLocation.Move(0, 3);
			Global::_player.Move(0, 2);
		}
		else
		{
			Global::_startingLocation.SetPosition(0, 720);
			Global::_upOne.SetPosition(0, 0);
			Global::_stateManager->SetState("UpOne");
		}
		break;
	case Global::Directions::downDir:
		break;
	default:
		break;
	}
}

bool OverworldStartLocation::CollisionCheck(int parentx, int parenty, int parentsize, int childx, int childy, int childsize)
{
	if (parentx - parentsize / 2 < childx + childsize / 2 &&
		parentx + parentsize / 2 > childx - childsize / 2 &&
		parenty - parentsize / 2 < childy + childsize / 2 &&
		parenty + parentsize / 2 > childy - childsize / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}