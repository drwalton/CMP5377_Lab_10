#include "App.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include <stdexcept>
#include <iostream>
#include <ranges>
#include <string>
#include <sstream>
#include "NetHighScoreManager.hpp"

const int fontSize = 32;
const int lineSpacing = 3;

App::App()
	:shouldQuit_(false), score_(0), state_(State::PLAYING)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		throw std::runtime_error("Failed to initialise video");
	}

	window_ = SDL_CreateWindow("Pong Game With High Scores", WIN_WIDTH, WIN_HEIGHT, 0);

	if (!window_) {
		throw std::runtime_error("Failed to create window");
	}

	renderer_ = SDL_CreateRenderer(window_, SDL_GPU_RENDERER);

	if (!renderer_) {
		throw std::runtime_error("Renderer creation failed");
	}

	SDL_SetRenderVSync(renderer_, 1);

	objs_.emplace_back(std::make_unique<Paddle>(renderer_));
	objs_.emplace_back(std::make_unique<Ball>(renderer_, static_cast<Paddle*>(objs_.back().get()), this));

	TTF_Init();
	font_ = TTF_OpenFont("../resources/Boxy-Bold.ttf", fontSize);
	if (!font_) {
		throw std::runtime_error("Failed to load ttf font file");
	}
}

App::~App()
{
	for (auto& obj : objs_) {
		obj.reset();
	}
	objs_.clear();

	TTF_CloseFont(font_);
}

void App::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_QUIT) {
			shouldQuit_ = true;
		}
		if (state_ == State::NAME_ENTRY) {
			if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.key >= SDLK_A && event.key.key <= SDLK_Z) {
					char c = (char)(event.key.key - SDLK_A + 'A');
					if (nameString_.size() < maxNameLength) {
						nameString_ += c;
					}
				}
				else if (event.key.key == SDLK_BACKSPACE && nameString_.length() > 0) {
					nameString_ = nameString_.substr(0, nameString_.size() - 1);
				}
				else if (event.key.key == SDLK_RETURN && nameString_.size() == 3)
				{
					NetHighScoreManager scoreManager("178.128.35.183");
					scoreManager.sendHighScore(nameString_, score_);
					highScoreText_ = scoreManager.getHighScores();
					state_ = State::GAME_OVER;
				}


			}
		}
	}

	if (state_ == State::PLAYING) {
		for (auto& obj : objs_) {
			obj->update();
		}
	}
	else {
		//TODO
	}
}

void App::draw()
{
	SDL_RenderClear(renderer_);

	if (state_ == State::PLAYING) {
		for (auto& obj : objs_) {
			obj->draw();
		}
	}


	std::string scoreText = "";
	if (state_ == State::GAME_OVER || state_ == State::NAME_ENTRY) {
		scoreText = "Game Over. Final Score: ";
	}
	else {
		scoreText = "Score: ";
	}
	scoreText += std::to_string(score_);

	drawTextLine(scoreText, 0, 0);

	if (state_ == State::GAME_OVER) {
		drawTextMultiline(highScoreText_, 50, 100);
	}
	else if (state_ == State::NAME_ENTRY) {
		drawTextLine("Enter Name: " + nameString_, 50, 100);
	}

	SDL_RenderPresent(renderer_);
}

bool App::shouldQuit()
{
	return shouldQuit_;
}

void App::addScore(int scoreToAdd)
{
	score_ += scoreToAdd;
}

void App::gameOver()
{
	state_ = State::NAME_ENTRY;
}

void App::drawTextLine(const std::string& text, int x, int y)
{
	const SDL_Color fColor{ 255, 255, 255 };

	SDL_Surface* fontSurface = TTF_RenderText_Solid(font_, text.c_str(), 0, fColor);
	SDL_FRect fontRect{ x, y, fontSurface->w, fontSurface->h };
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer_, fontSurface);

	SDL_RenderTexture(renderer_, tex, NULL, &fontRect);
	SDL_DestroySurface(fontSurface);
	SDL_DestroyTexture(tex);
}

std::vector<std::string> splitStringToLines(const std::string& text)
{
	auto result = std::vector<std::string>{};
	auto ss = std::stringstream{ text };

	for (std::string line; std::getline(ss, line, '\n');)
		result.push_back(line);

	return result;
}

void App::drawTextMultiline(const std::string& text, int x, int y)
{
	auto lines = splitStringToLines(text);
	for (int i = 0; i < lines.size(); ++i) {
		drawTextLine(lines[i], x, y + i * (fontSize + lineSpacing));
	}

}

