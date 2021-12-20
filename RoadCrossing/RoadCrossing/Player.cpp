#include "Player.h"

void Player::initTexture() {
	this->texture.loadFromFile("RPG.png");
}

void Player::initSprite() {
	this->sprite.setTexture(texture);
}

void Player::initVariable() {
	this->movementSpeed = 3.f;
}

Player::Player(float x, float y) {

	this->initVariable();

	this->initTexture();
	this->initSprite();
	this->sprite.setPosition(x, y);
}

Player::~Player()
{

}

void Player::UpdateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		this->sprite.move(0.f, -this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		this->sprite.move(-this->movementSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		this->sprite.move(0.f, this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		this->sprite.move(this->movementSpeed, 0.f);
	}
}

void Player::update(RenderTarget* TARGET)
{
	this->UpdateInput();
}

void Player::render(RenderTarget* TARGET)
{

	TARGET->draw(this->sprite);
}

void Player::collisionWindow()
{
	if (this->sprite.getPosition().x < 0)
		this->sprite.setPosition(0.f, this->sprite.getPosition().y);
	if (this->sprite.getPosition().y < 0)
		this->sprite.setPosition(this->sprite.getPosition().x, 0.f);
	if (this->sprite.getPosition().x + this->sprite.getGlobalBounds().width > 1200)
		this->sprite.setPosition(1200 - this->sprite.getGlobalBounds().width, this->sprite.getPosition().y);
	if (this->sprite.getPosition().y + this->sprite.getGlobalBounds().height > 900)
		this->sprite.setPosition(this->sprite.getPosition().x, 900 - this->sprite.getGlobalBounds().height);
}

