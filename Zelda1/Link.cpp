#include "Link.h"



Link::Link(SDL_Rect rect, int speed, SDL_Color color)
{
	_rect = rect;
	_speed = speed;
	_color = color;

}

SDL_Rect Link::GetRect()
{
	return _rect;
}

SDL_Color Link::GetColor()
{
	return _color;
}

void Link::Move(int x, int y)
{
	_rect.x += x;
	_rect.y += y;
}

void Link::GetPos(int x, int y)
{
	_rect.x = x;
	_rect.y = y;
}

void Link::Render(Renderer & renderer)
{
	renderer.DrawRect(GetRect(), GetColor());
}

Link::~Link()
{
}
