#pragma once

#include "Sprite.hpp"

class Paddle : public Sprite
{
public:
	Paddle(SDL_Renderer* renderer);
	~Paddle();

	void update() override;

	const SDL_FRect& getRect() const;

private:
	int lastFrameTime;

};


