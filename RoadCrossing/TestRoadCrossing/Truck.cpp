#include "Truck.h"

void Truck::initVariable()
{
	this->veclocity = 7;
}

void Truck::initTexture()
{
	if (!this->texture.loadFromFile("texture//Truck.png")) {
		cout << "ERROR load Truck";
	};
}

void Truck::initSprite(float posX, float posY)
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.7, 0.7);
	this->sprite.setPosition(posX, posY);
}

Truck::Truck(float posX, float posY)
{
	this->initVariable();
	this->initTexture();
	this->initSprite(posX, posY);
}

FloatRect Truck::getBound()
{
	return this->sprite.getGlobalBounds();
}

void Truck::updateMove()
{
	this->sprite.move(this->veclocity, 0);
}

void Truck::update()
{
	this->updateMove();
}

void Truck::render(RenderTarget * target)
{
	target->draw(this->sprite);
}
