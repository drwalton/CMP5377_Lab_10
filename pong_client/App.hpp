#pragma once

#include "GameObject.hpp"
#include "NetworkManager.hpp"
#include <vector>
#include <memory>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

class Ball;
class Paddle;

class App final {
public:
	App();
	~App();

	void update();
	void draw();

	bool shouldQuit();

	static const int WIN_WIDTH = 640, WIN_HEIGHT = 480;

private:
	void drawTextLine(const std::string& text, int x, int y);
	void drawTextMultiline(const std::string& text, int x, int y);

	std::vector<std::unique_ptr<GameObject>> objs_;
	Ball* ball_;
	Paddle* paddle1_;
	Paddle* paddle2_;
	SDL_Window* window_;
	SDL_Renderer* renderer_;
	bool shouldQuit_;
	int p1Score_, p2Score_;
	TTF_Font* font_;
	NetworkManager netManager_;
};

