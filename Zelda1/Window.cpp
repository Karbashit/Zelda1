#include "Window.h"



Window::Window(const std::string& title, int xpos, int ypos, int width, int height) : _window{ SDL_CreateWindow("Zelda 1 Clone (Alpha)", xpos, ypos, width, height, 0) }
{
	if (!_window) {
		throw std::runtime_error(SDL_GetError());
	}
}

Window::~Window()
{
	SDL_DestroyWindow(_window);
}

SDL_Window * Window::getPointer() const
{
	assert(_window != nullptr);
	return _window;
}

