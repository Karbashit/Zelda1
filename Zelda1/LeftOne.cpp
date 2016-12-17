#include "LeftOne.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Terrain.h"
#include "ServiceLocator.h"
#include "Window.h"
#include "Game.h"

void LeftOne::Enter()
{
	Global::_spriteLeftOne = Global::_renderer.CreateSprite(Global::_leftOneBmp, Global::_leftOne.GetRect().x, Global::_leftOne.GetRect().y,
		Global::_leftOne.GetRect().w, Global::_leftOne.GetRect().h);
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
}

void LeftOne::UpdatePlayerArea()
{
	if (Global::_player.GetRect().y < Global::_startingLocation.GetRect().y)
	{
		std::cout << "up" << std::endl;
	}
	if (Global::_player.GetRect().y > Global::_startingLocation.GetRect().y + 720)
	{
		std::cout << "down" << std::endl;
	}
	if (Global::_player.GetRect().x < Global::_startingLocation.GetRect().w - 1280)
	{
		std::cout << "left" << std::endl;
	}
	if (Global::_player.GetRect().x > Global::_startingLocation.GetRect().w)
	{
		Global::_stateManager->SetState("StartingLocation");
		Global::_player.Move(-1230, 0);
	}
}

