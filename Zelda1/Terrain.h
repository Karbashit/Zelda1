#pragma once
#include "SDLSystem.h"
#include "Renderer.h"

class Terrain
{
public:
	Terrain(SDL_Rect rect, SDL_Color color);
	~Terrain();

	SDL_Rect GetRect();
	SDL_Color GetColor();

	void Move(int x, int y);
	void SetPosition(int x, int y);
	void Render(Renderer& renderer);
private:
	SDL_Rect _rect;
	SDL_Color _color;

};

