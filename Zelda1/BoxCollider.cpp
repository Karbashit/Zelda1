#include "BoxCollider.h"

BoxCollider::BoxCollider(SDL_Rect rect, SDL_Color color)
{
	_rect = rect;
	_color = color;
}

SDL_Rect BoxCollider::GetRect()
{
	return _rect;
}

SDL_Color BoxCollider::GetColor()
{
	return _color;
}

void BoxCollider::Move(int x, int y)
{
	_rect.x += x;
	_rect.y += y;
}

void BoxCollider::SetPosition(int x, int y)
{
	_rect.x = x;
	_rect.y = y;
}

void BoxCollider::Render(Renderer & renderer)
{
	renderer.DrawRect(GetRect(), GetColor());
}

BoxCollider::~BoxCollider()
{
}
