#include "Renderer.h"

Renderer::Renderer(const Window& w) : _renderer{ SDL_CreateRenderer(w.getPointer(), -1, SDL_VIDEO_OPENGL) },
									  _surface{nullptr}
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
	SDL_SetRenderDrawColor(_renderer, 50, 100, 255, 0xff);
}

void Renderer::DrawRect(SDL_Rect rect, SDL_Color color)
{
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
}

void Renderer::DrawSprite(int x, int y, Sprite* sprite)
{
	SDL_Rect dstRect = { x, y, sprite->GetSource().w, sprite->GetSource().h };
	SDL_RenderCopy(_renderer, sprite->GetTexture(), &sprite->GetSource(), &dstRect);
}


void Renderer::Present()
{
	SDL_RenderPresent(_renderer);
}

void Renderer::FillRect(SDL_Rect rect)
{
	SDL_RenderFillRect(_renderer, &rect);
}

Sprite* Renderer::CreateSprite(const std::string file, unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	auto it = textures.find(file); // Returns an iterator to a pos or end, depending on success
	if (it == textures.end())
	{
		// If we do not find the texture we need to load it and inser it in to our std::map so
		// that we may create pointers to the same texture for several sprites.
		SDL_Surface* xSurface = SDL_LoadBMP(file.c_str());
		SDL_Texture* xTexture = SDL_CreateTextureFromSurface(_renderer, xSurface);
		SDL_SetSurfaceAlphaMod(xSurface, 0xff);
		SDL_SetColorKey(xSurface, SDL_TRUE, SDL_MapRGB(xSurface->format, 0, 0xff, 0xff));
		SDL_FreeSurface(xSurface);
		textures.insert(std::pair<std::string, SDL_Texture*>(file, xTexture));
		it = textures.find(file);

	}
	Sprite* xSprite = new Sprite(it->second, x, y, w, h);
	sprites.push_back(xSprite);
	return xSprite;
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(_renderer);
}
