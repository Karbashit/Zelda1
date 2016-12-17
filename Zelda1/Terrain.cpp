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

void Terrain::Render(Renderer & renderer)
{
	renderer.DrawRect(GetRect(), GetColor());
}

Terrain::~Terrain()
{
}
