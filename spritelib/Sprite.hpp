#pragma once

#include "GameObject.hpp"
#include <SDL3/SDL.h>
#include <string>

SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& file);

class Sprite : public GameObject {
protected:
	SDL_FRect rect_;
private:
	SDL_Texture* texture_;
public:
	Sprite(SDL_Renderer* renderer, const std::string& spriteFilename);
	~Sprite();

	Sprite(const Sprite&) = delete;
	Sprite& operator=(const Sprite&) = delete;
	
	void draw() override;

	float getX() const;
	float getY() const;
	float getW() const;
	float getH() const;
};

