#pragma once

#include "GameObject.hpp"
#include <vector>
#include <memory>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

class App final {
public:
	App();
	~App();

	void update();
	void draw();

	bool shouldQuit();

	static const int WIN_WIDTH = 640, WIN_HEIGHT = 480;

	void addScore(int scoreToAdd);
	void gameOver();

private:
	void drawTextLine(const std::string& text, int x, int y);
	void drawTextMultiline(const std::string& text, int x, int y);

	std::vector<std::unique_ptr<GameObject>> objs_;
	SDL_Window* window_;
	SDL_Renderer* renderer_;
	bool shouldQuit_;
	int score_;
	TTF_Font* font_;
	enum State {
		PLAYING, NAME_ENTRY, GAME_OVER
	};
	State state_;
	std::string highScoreText_;
	std::string nameString_;
	const int maxNameLength = 3;
};

