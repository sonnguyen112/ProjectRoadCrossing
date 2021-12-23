#include "Bat.h"

Bat::Bat()
	:Animal("huy_images/Bat/bat.png","huy_images/Bat/bat.flac", 0, 0, 17, 22, 3, Vector2f(0.f, 50.f), 1, -1) {}

void Bat::update(RenderTarget& target) {
	Animal::updateMovement();
	Animal::updateAnimations(0, 17, 51);
	if (getPosition().x <= -currentFrame.width) {
		setPosition(target.getSize().x, getPosition().y);
	}
}