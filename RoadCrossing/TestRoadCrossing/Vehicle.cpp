#include "Vehicle.h"


void Vehicle::initTexture(string fpath)
{
	if (!textureSheet.loadFromFile(fpath))
	{
		std::cout << "Could not load car image!" << "\n";
	}
}

void Vehicle::initSprite(
	float scale, Vector2f beginPos, float vel_, int direct_)
{
	sprite.setTexture(textureSheet);
	sprite.setScale(scale, scale);
	sprite.setPosition(beginPos);
	vel = vel_;
	direct = direct_;
}

Vehicle::Vehicle(string fpath,
	float scale, Vector2f beginPos, float vel_, int direct_)
{
	initTexture(fpath);
	initSprite(scale, beginPos, vel_, direct_);
}

Vector2f Vehicle::getPosition()
{
	return sprite.getPosition();
}

FloatRect Vehicle::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

float Vehicle::getVel()
{
	return this->vel;
}

void Vehicle::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Vehicle::setVel(float vel)
{
	this->vel = vel;
}


void Vehicle::updateMovement()
{
	sprite.move(vel*direct, 0.f);
}


void Vehicle::render(RenderTarget & target)
{
	target.draw(sprite);
}
