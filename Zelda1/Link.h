#pragma once
#include "SDLSystem.h"
#include "Renderer.h"

class Link
{
public:
	Link(SDL_Rect rect, int speed, SDL_Color color);
	~Link();

	SDL_Rect GetRect();
	SDL_Color GetColor();

	void Move(int x, int y);
	void GetPos(int x, int y);

	void Render(Renderer& renderer);
private:
	SDL_Rect _rect;
	int _speed;
	SDL_Color _color;

};

