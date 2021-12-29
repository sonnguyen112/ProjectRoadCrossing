#include "Truck.h"

Truck::Truck()
	:Vehicle("img/Vehicle/truck.png", 0.2, Vector2f(-100.f, 520.f), 0.7, 1) {}

void Truck::update(RenderTarget& target) {
	Vehicle::updateMovement();

	if (getPosition().x >= target.getSize().x) {
		setPosition(-100, getPosition().y);
	}
}