#include "Player.h"

void Player::initVariable()
{
	this->veclocity = 5;
	this->curFrame = IntRect(0, 0, 150, 142);
}

void Player::initTexture()
{
	this->texture.loadFromFile("PlayerImage//RPG.png");
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.scale(1, 1);
	//this->sprite.setTextureRect(this->curFrame);
}

Player::Player()
{
	this->initVariable();
	this->initTexture();
	this->initSprite();
}

FloatRect Player::getBound()
{
	return this->sprite.getGlobalBounds();
}

float Player::getVel()
{
	return this->veclocity;
}

Vector2f Player::getMidPoint()
{
	Vector2f res;
	res.x = (this->sprite.getPosition().x + this->sprite.getPosition().x + this->sprite.getGlobalBounds().width) / 2.f;
	res.y = (this->sprite.getPosition().y + this->sprite.getPosition().y + this->sprite.getGlobalBounds().height) / 2.f;
	return res;
}

void Player::setPos(float x, float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setVel(float vel)
{
	this->veclocity = vel;
}

void Player::PlayerCol()
{
	this->sprite.setRotation(90);
}

void Player::updateCurFrame()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2) {
		this->curFrame.left += 150;
		if (this->curFrame.left >= 900) {
			this->curFrame.left = 0;
		}
		this->animationTimer.restart();
		this->curFrame.top = 40;
		this->curFrame.height = 100;
		this->curFrame.width = 120;
		this->sprite.setTextureRect(this->curFrame);
	}
	
}

void Player::updateMove()
{
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		this->sprite.move(0, -this->veclocity);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		this->sprite.move(0, this->veclocity);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		this->sprite.move(-this->veclocity, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		this->sprite.move(this->veclocity, 0);
	}
}

void Player::update()
{
	this->updateMove();
	//this->updateCurFrame();
}

void Player::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
