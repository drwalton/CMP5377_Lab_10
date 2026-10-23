#include "Ball.hpp"
#include "App.hpp"
#include "Paddle.hpp"

Ball::Ball(SDL_Renderer* renderer, const Paddle* paddle1, const Paddle* paddle2, App* app)
	:Sprite(renderer, "../resources/GREENBALL.png"), 
	paddle1_(paddle1), paddle2_(paddle2), app_(app)
{
	lastFrameTime_ = SDL_GetTicks();
	reset();
}

Ball::~Ball()
{
}

void Ball::reset()
{
	rect_.x = App::WIN_WIDTH / 2;
	rect_.y = App::WIN_HEIGHT / 2;

	xSpeed_ = 2.0f; 
	ySpeed_ = 2.0f * (rand() % 2 == 0 ? 1 : -1);
}

void Ball::update() 
{
	float frameDuration = (SDL_GetTicks() - lastFrameTime_) / 1000.f;
	lastFrameTime_ = SDL_GetTicks();

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
	if (SDL_HasRectIntersectionFloat(&rect_, &(paddle1_->getRect()))) {
		ySpeed_ = -abs(ySpeed_);
		rect_.y = fminf(rect_.y, paddle1_->getRect().y - rect_.h);
	}

	if (SDL_HasRectIntersectionFloat(&rect_, &(paddle2_->getRect()))) {
		ySpeed_ = abs(ySpeed_);
		rect_.y = fmaxf(rect_.y, paddle2_->getRect().y + paddle2_->getRect().h);
	}

	if (rect_.y > App::WIN_HEIGHT) {
		app_->addP2Score(1);
	}

	if (rect_.y < 0) {
		app_->addP1Score(1);
	}

}

