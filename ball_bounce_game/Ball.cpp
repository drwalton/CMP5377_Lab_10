#include "Ball.hpp"
#include "App.hpp"
#include "Paddle.hpp"

Ball::Ball(SDL_Renderer* renderer, const Paddle* paddle, App* app)
	:Sprite(renderer, "../resources/GREENBALL.png"), paddle_(paddle), app_(app)
{
	rect_.x = App::WIN_WIDTH / 2;
	rect_.y = 40;

	xSpeed_ = 2.0f; 
	ySpeed_ = 0.0f;

	lastFrameTime_ = SDL_GetTicks();
}

Ball::~Ball()
{
}

void Ball::update() 
{
	float frameDuration = (SDL_GetTicks() - lastFrameTime_) / 1000.f;
	lastFrameTime_ = SDL_GetTicks();

	const float acceleration = 10.0f;

	ySpeed_ += acceleration * frameDuration;

	rect_.x += xSpeed_;
	rect_.y += ySpeed_;

	// Collision Check

	// Bounce off walls.
	if (rect_.x < 0.0f) {
		xSpeed_ = abs(xSpeed_);
		rect_.x = 0.0f;
	}
	else if (rect_.x > App::WIN_WIDTH - rect_.w) {
		xSpeed_ = -abs(xSpeed_);
		rect_.x = App::WIN_WIDTH - rect_.w;
	}

	// Bounce off paddle.
	if (SDL_HasRectIntersectionFloat(&rect_, &(paddle_->getRect()))) {
		ySpeed_ = -abs(ySpeed_);
		rect_.y = fminf(rect_.y, paddle_->getRect().y - rect_.h);
		app_->addScore(1);
	}

	if (rect_.y > App::WIN_HEIGHT) {
		app_->gameOver();
	}

}

