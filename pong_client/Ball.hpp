#pragma once
#include "Sprite.hpp"

class Paddle;
class App;

class Ball : public Sprite {
public:
	Ball(SDL_Renderer* renderer);
	~Ball();

	void setPos(float x, float y);

	void update() override;
private:
};

