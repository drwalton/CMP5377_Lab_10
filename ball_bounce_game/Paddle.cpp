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

void Paddle::update()
{
	float frameDuration = (SDL_GetTicks() - lastFrameTime) / 1000.f;
	lastFrameTime = SDL_GetTicks();


	int keyCount;
	const bool* keyStates = SDL_GetKeyboardState(&keyCount);

	const float speed = 500.0f;

	if (keyStates[SDL_SCANCODE_LEFT]) {
		rect_.x -= speed * frameDuration;
		rect_.x = fmaxf(rect_.x, 0.0f);
	}
	if (keyStates[SDL_SCANCODE_RIGHT]) {
		rect_.x += speed * frameDuration;
		rect_.x = fminf(rect_.x, App::WIN_WIDTH - rect_.w);
	}


}

const SDL_FRect& Paddle::getRect() const
{
	return rect_;
}
