#include "Bat.h"

Bat::Bat()
	:Animal("huy_images/Bat/killer_bat.png", 0, 64, 48, 64, 3, Vector2f(0.f, 50.f), 1){}

void Bat::update() {
	Animal::updateMovement();
	Animal::updateAnimations(64, 48, 144);
}