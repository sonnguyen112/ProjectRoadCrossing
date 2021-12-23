#include "Truck.h"

Truck::Truck()
	:Vehicle("img/Vehicle/truck.png", 0, 0, 800, 600, 0.2, Vector2f(-204.f, 450.f), 0.7, 1) {}

void Truck::update(RenderTarget& target) {
	Vehicle::updateMovement();
	
	if (getPosition().x >= target.getSize().x) {
		setPosition(0, getPosition().y);
	}
}