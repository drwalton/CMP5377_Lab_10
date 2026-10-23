#pragma once
#include <SDL3/SDL.h>


class GameObject {
public:
	GameObject(SDL_Renderer* renderer);
	virtual ~GameObject();
	virtual void update() = 0;
	virtual void draw() = 0;
protected:
	SDL_Renderer* renderer_;
};
