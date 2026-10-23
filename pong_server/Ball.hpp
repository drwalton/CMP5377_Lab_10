#pragma once
#include "Sprite.hpp"

class Paddle;
class App;

class Ball : public Sprite {
public:
	Ball(SDL_Renderer* renderer, const Paddle* paddle1, const Paddle* paddle2, App* app);
	~Ball();

	void update() override;

	void reset();


private:
	float xSpeed_, ySpeed_, lastFrameTime_;
	const Paddle* paddle1_;
	const Paddle* paddle2_;
	App* app_;
};

