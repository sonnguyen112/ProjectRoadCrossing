#include "Car.h"
#include "..\..\TestRoadCrossing\TestRoadCrossing\Car.h"

void Car::initVariable()
{
	this->veclocity = 5;
}

void Car::initTexture()
{
	if (!this->texture.loadFromFile("texture//car.png")) {
		cout << "ERROR load car";
	};
}

void Car::initSprite(float posX, float posY)
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.2, 0.2);
	this->sprite.setPosition(posX, posY);
}

Car::Car(float posX, float posY)
{
	this->initVariable();
	this->initTexture();
	this->initSprite(posX, posY);
}

FloatRect Car::getBound()
{
	return this->sprite.getGlobalBounds();
}

void Car::updateMove()
{
	this->sprite.move(this->veclocity, 0);
}

void Car::update()
{
	this->updateMove();
}

void Car::render(RenderTarget * target)
{
	target->draw(this->sprite);
}
