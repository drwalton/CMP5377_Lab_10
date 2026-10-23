#include "Sprite.hpp"
#include <stdexcept>

SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& file)
{
	SDL_Surface* surf = SDL_LoadSurface(file.c_str());
	if (!surf) {
		throw std::runtime_error("Couldn't load texture \"" + file + "\"");
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_DestroySurface(surf);
	return texture;
}

Sprite::Sprite(SDL_Renderer* renderer, const std::string& spriteFilename)
	:GameObject(renderer) 
{
	texture_ = loadTexture(renderer_, spriteFilename);
	SDL_GetTextureSize(texture_, &(rect_.w), &(rect_.h));
	rect_.x = rect_.y = 0;
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture_);
}

void Sprite::draw()
{
	SDL_RenderTexture(renderer_, texture_, nullptr, &rect_);	
}

float Sprite::getX() const
{
	return rect_.x;
}

float Sprite::getY() const
{
	return rect_.y;
}

float Sprite::getW() const
{
	return rect_.w;
}

float Sprite::getH() const
{
	return rect_.h;
}

