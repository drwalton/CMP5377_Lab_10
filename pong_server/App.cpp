#include "App.hpp"
#include "PlayerPaddle.hpp"
#include "RemotePaddle.hpp"
#include "Ball.hpp"
#include <stdexcept>
#include <iostream>
#include <ranges>
#include <string>
#include <sstream>


const int fontSize = 32;
const int lineSpacing = 3;

App::App()
	:netManager_("localhost", 5000, 5001),
	shouldQuit_(false), p1Score_(0), p2Score_(0)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		throw std::runtime_error("Failed to initialise video");
	}

	window_ = SDL_CreateWindow("Pong Game Server", WIN_WIDTH, WIN_HEIGHT, 0);

	if (!window_) {
		throw std::runtime_error("Failed to create window");
	}

	renderer_ = SDL_CreateRenderer(window_, SDL_GPU_RENDERER);

	if (!renderer_) {
		throw std::runtime_error("Renderer creation failed");
	}

	SDL_SetRenderVSync(renderer_, 1);

	objs_.emplace_back(std::make_unique<PlayerPaddle>(renderer_));
	paddle1_ = static_cast<Paddle*>(objs_.back().get());
	objs_.emplace_back(std::make_unique<RemotePaddle>(renderer_));
	paddle2_ = static_cast<RemotePaddle*>(objs_.back().get());
	objs_.emplace_back(std::make_unique<Ball>(renderer_, 
		paddle1_, paddle2_, this));
	ball_ = static_cast<Ball*>(objs_.back().get());

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
	}

	for (auto& obj : objs_) {
		obj->update();
	}

	netManager_.sendState(
		ball_->getX(), ball_->getY(),
		paddle1_->getX(), paddle2_->getX(),
		p1Score_, p2Score_);

	netManager_.checkForRemoteInput();
	paddle2_->setInput(netManager_.getCurrInput());
}

void App::draw()
{
	SDL_RenderClear(renderer_);

	for (auto& obj : objs_) {
		obj->draw();
	}

	std::string scoreText = "";
	scoreText = "P1 Score: " + std::to_string(p1Score_) + 
		" P2 Score: " + std::to_string(p2Score_);

	drawTextLine(scoreText, 0, 0);

	SDL_RenderPresent(renderer_);
}

bool App::shouldQuit()
{
	return shouldQuit_;
}

void App::addP1Score(int scoreToAdd)
{
	p1Score_ += scoreToAdd;
	newPoint();
}
void App::addP2Score(int scoreToAdd)
{
	p2Score_ += scoreToAdd;
	newPoint();
}

void App::newPoint()
{
	ball_->reset();
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

