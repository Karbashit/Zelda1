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

void Renderer::DrawSprite(Sprite * sprite, int x, int y)
{
	SDL_Rect dstRect = { x, y, sprite};
}


void Renderer::Present()
{
	SDL_RenderPresent(_renderer);
}

Sprite* Renderer::CreateSprite(const std::string p_file, unsigned int p_x, unsigned int p_y,
	unsigned int p_w, unsigned int p_h)
{
	auto it = m_textures.find(p_file); // Returns an iterator to a pos or end, depending on success
	if (it == m_textures.end())
	{
		// If we do not find the texture we need to load it and inser it in to our std::map so
		// that we may create pointers to the same texture for several sprites.
		SDL_Surface* xSurface = SDL_LoadBMP(p_file.c_str());
		SDL_SetColorKey(xSurface, SDL_TRUE, SDL_MapRGB(xSurface->format, 160, 64, 192));
		SDL_Texture* xTexture = SDL_CreateTextureFromSurface(_renderer, xSurface);

		SDL_FreeSurface(xSurface);
		m_textures.insert(std::pair<std::string, SDL_Texture*>(p_file, xTexture));
		it = m_textures.find(p_file);

	}
	Sprite* xSprite = new Sprite(it->second, p_x, p_y, p_w, p_h);
	m_sprites.push_back(xSprite);
	return xSprite;
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(_renderer);
}
