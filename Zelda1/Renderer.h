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
	void DrawSprite(int x, int y, Sprite* sprite);
	void Present();
	void FillRect(SDL_Rect rect);

	Sprite* CreateSprite(const std::string file, unsigned int x, unsigned int y, unsigned int w, unsigned int h);

private:
	SDL_Renderer* _renderer;
	Renderer(const Renderer&) = delete;
	Renderer& operator=(Renderer&) = delete;
	std::map<std::string, SDL_Texture*> textures;
	std::vector<Sprite*> sprites;
};

