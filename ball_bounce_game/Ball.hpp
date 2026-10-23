#pragma once
#include "Sprite.hpp"

class Paddle;
class App;

class Ball : public Sprite {
public:
	Ball(SDL_Renderer* renderer, const Paddle* paddle, App* app);
	~Ball();

	void update() override;

private:
	float xSpeed_, ySpeed_, lastFrameTime_;
	const Paddle* paddle_;
	App* app_;
};

