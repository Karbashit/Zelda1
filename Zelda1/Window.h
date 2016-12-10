#pragma once
#include "SDLSystem.h"

class Window
{
public:
	Window(const std::string& title, int xpos, int ypos, int width, int height);
	~Window();
	SDL_Window* getPointer() const;

private:
	Window(const Window&) = delete;
	Window& operator=(Window&) = delete;
	SDL_Window* _window;
};

