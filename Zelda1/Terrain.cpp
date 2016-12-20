#include "Terrain.h"

Terrain::Terrain(SDL_Rect rect, SDL_Color color)
{
	_rect = rect;
	_color = color;
}

SDL_Rect Terrain::GetRect()
{
	return _rect;
}

SDL_Color Terrain::GetColor()
{
	return _color;
}

void Terrain::Move(int x, int y)
{
	_rect.x += x;
	_rect.y += y;
}

void Terrain::SetPosition(int x, int y)
{
	_rect.x = x;
	_rect.y = y;
}

void Terrain::Render(Renderer & renderer)
{
	renderer.DrawRect(GetRect(), GetColor());
}

Terrain::~Terrain()
{
}
