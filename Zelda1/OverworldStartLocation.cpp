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

}

void OverworldStartLocation::Exit()
{
}

void OverworldStartLocation::Draw()
{
	Global::_renderer.DrawSprite(Global::_startingLocation.GetRect().x, Global::_startingLocation.GetRect().y, Global::_spriteStartingLocation);
	Global::_startingLocation.Render(Global::_renderer);
}
