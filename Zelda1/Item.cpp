#include "Item.h"

Item::Item(SDL_Rect rect, SDL_Color color)
{
	_rect = rect;
	_color = color;
}

SDL_Rect Item::GetRect()
{
	return _rect;
}

SDL_Color Item::GetColor()
{
	return _color;
}

void Item::Move(int x, int y)
{
	_rect.x += x;
	_rect.y += y;
}

void Item::SetPosition(int x, int y)
{
	_rect.x = x;
	_rect.y = y;
}

void Item::Render(Renderer & renderer)
{
	renderer.DrawRect(GetRect(), GetColor());
}

Item::~Item()
{
}
