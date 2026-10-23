#pragma once

#include "Sprite.hpp"

class Paddle : public Sprite
{
public:
	Paddle(SDL_Renderer* renderer);
	~Paddle();

	void update() override;

	void setX(float x);
	void setY(float y);

};


