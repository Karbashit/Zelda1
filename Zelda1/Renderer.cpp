#include "Renderer.h"

Renderer::Renderer(const Window& w) : _renderer{ SDL_CreateRenderer(w.getPointer(), -1, SDL_VIDEO_OPENGL) }
{
}

SDL_Renderer * Renderer::getPointer() const
{
	assert(_renderer != nullptr);
	return _renderer;
}

void Renderer::Update()
{
	SDL_RenderClear(_renderer);
	SDL_SetRenderDrawColor(_renderer, 50, 50, 255, 255);
}

void Renderer::DrawRect(SDL_Rect rect, SDL_Color color)
{
	SDL_RenderFillRect(_renderer, &rect);
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
}

void Renderer::Present()
{
	SDL_RenderPresent(_renderer);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(_renderer);
}
