#include "Vehicle.h"


void Vehicle::initTexture(string fpath)
{
	if (!textureSheet.loadFromFile(fpath))
	{
		std::cout << "Could not load car image!" << "\n";
	}
}

void Vehicle::initSprite(int left, int top, int width, int height, 
	float scale, Vector2f beginPos, float vel_, int direct_)
{
	sprite.setTexture(textureSheet);
	currentFrame = sf::IntRect(left, top, width, height);

	sprite.setTextureRect(currentFrame);
	sprite.setScale(scale, scale);
	sprite.setPosition(beginPos);
	vel = vel_;
	direct = direct_;
}

void Vehicle::initAnimations()
{
	animationTimer.restart();
}

Vehicle::Vehicle(string fpath, int left, int top, int width, int height, 
	float scale, Vector2f beginPos, float vel_, int direct_)
{
	initTexture(fpath);
	initSprite(left, top, width, height, scale, beginPos, vel_, direct_);
	initAnimations();
}

Vector2f Vehicle::getPosition()
{
	return sprite.getPosition();
}

FloatRect Vehicle::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

void Vehicle::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}


void Vehicle::updateMovement()
{
	sprite.move(vel*direct, 0.f);
}

void Vehicle::updateAnimations(int top, int widthPerImage, int maxWidthImage)
{
	if (animationTimer.getElapsedTime().asSeconds() >= 0.15f)
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

void Vehicle::render(RenderTarget & target)
{
	target.draw(sprite);
}
