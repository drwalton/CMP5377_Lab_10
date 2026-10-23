#pragma once

#include "Paddle.hpp"

class RemotePaddle : public Paddle {
public:
	RemotePaddle(SDL_Renderer* renderer);
	~RemotePaddle();

	void update() override;

	void setInput(float input);
private:
	float input_;
};

