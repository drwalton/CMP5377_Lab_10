#include "Paddle.hpp"
#include "App.hpp"

Paddle::Paddle(SDL_Renderer* renderer)
	:Sprite(renderer, "../resources/GREENPADDLE.png")
{
	rect_.x = (App::WIN_WIDTH / 2) - (rect_.w / 2);
}

Paddle::~Paddle()
{
}

void Paddle::update()
{
}

void Paddle::setX(float x)
{
	rect_.x = x;
}

void Paddle::setY(float y)
{
	rect_.y = y;
}

