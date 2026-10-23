#pragma once

#include "Paddle.hpp"

class PlayerPaddle : public Paddle
{
public:
	PlayerPaddle(SDL_Renderer* renderer);
	~PlayerPaddle();

	void update() override;

};
