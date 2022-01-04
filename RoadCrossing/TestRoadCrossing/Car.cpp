#include "Car.h"

Car::Car()
	:Vehicle("img/Vehicle/car.png", 0.8, Vector2f(1000.f, 380.f), 1, -1) {
	cout << "abc";
}

void Car::update(RenderTarget& target) {
	Vehicle::updateMovement();
	if (getPosition().x + this->getGlobalBounds().width <= 0) {
		setPosition(1000, getPosition().y);
	}
}