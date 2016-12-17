#include "RightOne.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Terrain.h"
#include "ServiceLocator.h"
#include "Window.h"
#include "Game.h"

void RightOne::Enter()
{
	Global::_spriteRightOne = Global::_renderer.CreateSprite(Global::_rightOneBmp, Global::_rightOne.GetRect().x, Global::_rightOne.GetRect().y,
		Global::_rightOne.GetRect().w, Global::_rightOne.GetRect().h);
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
}

void RightOne::UpdatePlayerArea()
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
		Global::_stateManager->SetState("StartingLocation");
		Global::_player.Move(1280, 0);
	}
	if (Global::_player.GetRect().x > Global::_startingLocation.GetRect().w)
	{
		std::cout << "right" << std::endl;
	}
}

