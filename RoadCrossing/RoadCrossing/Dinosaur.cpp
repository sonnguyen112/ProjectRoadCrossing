#include "Dinosaur.h"

Dinosaur::Dinosaur()
	:Animal("huy_images/Dinosaur/wolf.png", 0, 0, 204, 121, 1, Vector2f(-204.f, 200.f), 0.7) {}

void Dinosaur::update() {
	Animal::updateMovement();
	Animal::updateAnimations(0, 204, 1224);
}