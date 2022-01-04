#include "Dinosaur.h"

Dinosaur::Dinosaur()
	:Animal("huy_images/Dinosaur/dino.png", "huy_images/Dinosaur/dino.flac", 0, 0, 137, 154, 0.5, Vector2f(-204.f, 235.f), 0.7, 1) {}

void Dinosaur::update(RenderTarget& target) {
	Animal::updateMovement();
	Animal::updateAnimations(0, 137, 548);
	if (getPosition().x >= target.getSize().x) {
		setPosition(0, getPosition().y);
	}
}