#include "Npc.h"

Npc::Npc(SDL_Rect rect, SDL_Color color)
{
	_rect = rect;
	_color = color;
}

SDL_Rect Npc::GetRect()
{
	return _rect;
}

SDL_Color Npc::GetColor()
{
	return _color;
}

void Npc::Move(int x, int y)
{
	_rect.x += x;
	_rect.y += y;
}

void Npc::SetPosition(int x, int y)
{
	_rect.x = x;
	_rect.y = y;
}

void Npc::Render(Renderer & renderer)
{
	renderer.DrawRect(GetRect(), GetColor());
}

Npc::~Npc()
{
}
