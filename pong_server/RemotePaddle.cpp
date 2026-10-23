#include "RemotePaddle.hpp"

RemotePaddle::RemotePaddle(SDL_Renderer* renderer)
	:Paddle(renderer), input_(0)
{
	rect_.y = 40;
}

RemotePaddle::~RemotePaddle()
{
}

void RemotePaddle::update()
{
	float frameDuration = (SDL_GetTicks() - lastFrameTime) / 1000.f;
	lastFrameTime = SDL_GetTicks();

	const float speed = 500.0f;

	rect_.x += input_ * speed * frameDuration;
	rect_.x = fmaxf(rect_.x, 0.0f);
}

void RemotePaddle::setInput(float input) {
	input_ = input;
}
