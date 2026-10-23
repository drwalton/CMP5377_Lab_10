#pragma once

#include "Sprite.hpp"

class Paddle : public Sprite
{
public:
	Paddle(SDL_Renderer* renderer);
	~Paddle();

	const SDL_FRect& getRect() const;

protected:
	int lastFrameTime;

};


