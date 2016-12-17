#include "UpOne.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Terrain.h"
#include "ServiceLocator.h"
#include "Window.h"
#include "Game.h"

void UpOne::Enter()
{
	Global::_spriteUpOne = Global::_renderer.CreateSprite(Global::_upOneBmp, Global::_upOne.GetRect().x, Global::_upOne.GetRect().y,
		Global::_upOne.GetRect().w, Global::_upOne.GetRect().h);
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
}

void UpOne::UpdatePlayerArea()
{
	if (Global::_player.GetRect().y < Global::_startingLocation.GetRect().y)
	{
		std::cout << "up" << std::endl;
	}
	if (Global::_player.GetRect().y > Global::_startingLocation.GetRect().y + 720)
	{
		Global::_stateManager->SetState("StartingLocation");
		Global::_player.Move(0, -670);
	}
	if (Global::_player.GetRect().x < Global::_startingLocation.GetRect().w - 1280)
	{
		std::cout << "left" << std::endl;
	}
	if (Global::_player.GetRect().x > Global::_startingLocation.GetRect().w)
	{
		std::cout << "right" << std::endl;
	}
}

