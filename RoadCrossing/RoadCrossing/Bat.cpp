#include "Bat.h"

Bat::Bat()
	:Animal("huy_images/Bat/bat.png", 0, 192, 48, 64, 3, Vector2f(0.f, 50.f), 1, -1){}

void Bat::update(RenderTarget& target) {
	Animal::updateMovement();
	Animal::updateAnimations(192, 48, 144);
	if (getPosition().x <= -currentFrame.width) {
		setPosition(target.getSize().x, getPosition().y);
	}
}