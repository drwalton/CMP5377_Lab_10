#include "PlayerPaddle.hpp"
#include "App.hpp"

PlayerPaddle::PlayerPaddle(SDL_Renderer* renderer)
	:Paddle(renderer)
{
	rect_.y = App::WIN_HEIGHT - rect_.h - 40;
}

PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::update()
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
