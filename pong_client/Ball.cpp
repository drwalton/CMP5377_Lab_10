#include "Ball.hpp"

Ball::Ball(SDL_Renderer* renderer)
	:Sprite(renderer, "../resources/GREENBALL.png")
{
}

Ball::~Ball()
{
}

void Ball::setPos(float x, float y)
{
	rect_.x = x;
	rect_.y = y;
}

void Ball::update()
{
}


