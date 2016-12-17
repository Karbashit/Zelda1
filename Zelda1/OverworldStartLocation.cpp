#include "OverworldStartLocation.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Terrain.h"
#include "ServiceLocator.h"
#include "Window.h"
#include "Game.h"

void OverworldStartLocation::Enter()
{
	Global::_spriteStartingLocation = Global::_renderer.CreateSprite(Global::_startingLocationBmp, Global::_startingLocation.GetRect().x, Global::_startingLocation.GetRect().y,
													Global::_startingLocation.GetRect().w, Global::_startingLocation.GetRect().h);
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
	Global::_renderer.DrawSprite(Global::_startingLocation.GetRect().x, Global::_startingLocation.GetRect().y, Global::_spriteStartingLocation);
	Global::_startingLocation.Render(Global::_renderer);
}

void OverworldStartLocation::UpdatePlayerArea()
{
	if (Global::_player.GetRect().y < Global::_startingLocation.GetRect().y)
	{
		Global::_stateManager->SetState("UpOne");
		Global::_player.Move(0, 670);
	}
	if (Global::_player.GetRect().y > Global::_startingLocation.GetRect().y + 720)
	{
		std::cout << "down" << std::endl;
	}
	if (Global::_player.GetRect().x < Global::_startingLocation.GetRect().w - 1280)
	{
		Global::_stateManager->SetState("LeftOne");
		Global::_player.Move(1230, 0);
	}
	if (Global::_player.GetRect().x > Global::_startingLocation.GetRect().w)
	{
		Global::_stateManager->SetState("RightOne");
		Global::_player.Move(-1230, 0);
	}
}
