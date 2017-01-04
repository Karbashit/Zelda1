#include "FirstSwordDungeon.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Terrain.h"
#include "ServiceLocator.h"
#include "Window.h"
#include "Game.h"

void FirstSwordDungeon::Enter()
{
	Global::_oldMan.SetPosition(600, 263);
	Global::_masterSword.SetPosition(600, 400);
}

void FirstSwordDungeon::Update(float p_delta)
{
	UpdatePlayerArea();

	if(AquireSword(Global::_player.GetRect().x, Global::_player.GetRect().y, 100, Global::_masterSword.GetRect().x, Global::_masterSword.GetRect().y, 100))
	{
		Global::swordAquired = 1;
		Global::_masterSword.SetPosition(3000, 3000);
	}
}

void FirstSwordDungeon::Exit()
{
}

void FirstSwordDungeon::Draw()
{
	Global::_renderer.DrawSprite(Global::_firstSwordDung.GetRect().x, Global::_firstSwordDung.GetRect().y, Global::_spriteFirstSwordDung);
	Global::_firstSwordDung.Render(Global::_renderer);

	Global::_renderer.DrawSprite(Global::_oldMan.GetRect().x, Global::_oldMan.GetRect().y, Global::_spriteOldMan);
	Global::_oldMan.Render(Global::_renderer);

	Global::_renderer.DrawSprite(Global::_masterSword.GetRect().x, Global::_masterSword.GetRect().y, Global::_spriteMasterSword);
	Global::_masterSword.Render(Global::_renderer);
}

void FirstSwordDungeon::UpdatePlayerArea()
{
	if (Global::_player.GetRect().y < Global::_startingLocation.GetRect().y)
	{

	}
	if (Global::_player.GetRect().y > Global::_startingLocation.GetRect().y + 720)
	{
		Global::_stateManager->SetState("StartingLocation");
		Global::_player.GetPos(300, 150);
	}
	if (Global::_player.GetRect().x < Global::_startingLocation.GetRect().w - 1280)
	{

	}
	if (Global::_player.GetRect().x > Global::_leftOne.GetRect().x + 1280)
	{

	}
}

bool FirstSwordDungeon::AquireSword(int parentx, int parenty, int parentsize, int childx, int childy, int childsize)
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