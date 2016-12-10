#pragma once
#include "SDLSystem.h"
#include "Window.h"

class Renderer
{
public:
	Renderer(const Window& w);
	~Renderer();

	SDL_Renderer* getPointer() const;

	void Update();
	void DrawRect(SDL_Rect rect, SDL_Color color);
	void Present();

private:
	SDL_Renderer* _renderer;
	Renderer(const Renderer&) = delete;
	Renderer& operator=(Renderer&) = delete;
};

