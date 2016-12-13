#pragma once
#include "SDLSystem.h"
#include "Window.h"
#include "Sprite.h"

class Sprite;

class Renderer
{
public:
	Renderer(const Window& w);
	~Renderer();

	SDL_Renderer* getPointer() const;

	void Update();
	void DrawRect(SDL_Rect rect, SDL_Color color);
	void DrawSprite(Sprite* sprite, int x, int y);
	void Present();
	Sprite* CreateSprite(const std::string p_file, unsigned int p_x, unsigned int p_y, unsigned int p_w, unsigned int p_h);

private:
	SDL_Renderer* _renderer;
	SDL_Surface* _surface;
	Renderer(const Renderer&) = delete;
	Renderer& operator=(Renderer&) = delete;
	std::map<std::string, SDL_Texture*> m_textures;
	std::vector<Sprite*> m_sprites;
};

