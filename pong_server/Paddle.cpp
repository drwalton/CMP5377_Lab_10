#include "Paddle.hpp"
#include "App.hpp"

Paddle::Paddle(SDL_Renderer* renderer)
	:Sprite(renderer, "../resources/GREENPADDLE.png")
{
	rect_.x = (App::WIN_WIDTH / 2) - (rect_.w / 2);
	rect_.y = App::WIN_HEIGHT - rect_.h - 40;
	lastFrameTime = SDL_GetTicks();
}

Paddle::~Paddle()
{
}

const SDL_FRect& Paddle::getRect() const
{
	return rect_;
}
