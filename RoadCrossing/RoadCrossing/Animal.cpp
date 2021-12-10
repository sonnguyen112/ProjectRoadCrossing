#include "Animal.h"


void Animal::initTexture(string fpath)
{
	if (!textureSheet.loadFromFile(fpath))
	{
		std::cout << "Could not load the bat image!" << "\n";
	}
}

void Animal::initSprite(int left, int top, int width, int height, float scale, Vector2f beginPos, float vel_)
{
	sprite.setTexture(textureSheet);
	currentFrame = sf::IntRect(left, top, width, height);

	sprite.setTextureRect(currentFrame);
	sprite.setScale(scale, scale);
	sprite.setPosition(beginPos);
	vel = vel_;
}

void Animal::initAnimations()
{
	animationTimer.restart();
}

Animal::Animal(string fpath, int left, int top, int width, int height, float scale, Vector2f beginPos, float vel_)
{
	initTexture(fpath);
	initSprite(left, top, width, height, scale, beginPos, vel_);
	initAnimations();
}

Vector2f Animal::getPosition()
{
	return sprite.getPosition();
}

FloatRect Animal::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

void Animal::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}


void Animal::updateMovement()
{
	sprite.move(vel, 0.f);
}

void Animal::updateAnimations(int top, int widthPerImage, int maxWidthImage)
{
	if (animationTimer.getElapsedTime().asSeconds() >= 0.10f)
	{
		currentFrame.top = top;
		currentFrame.left += widthPerImage;
		if (currentFrame.left >= maxWidthImage) {
			currentFrame.left = 0;
		}

		animationTimer.restart();
		sprite.setTextureRect(currentFrame);
	}
}

void Animal::render(RenderTarget & target)
{
	target.draw(sprite);
}
