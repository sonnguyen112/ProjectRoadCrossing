#include "Car.h"

Car::Car()
	:Vehicle("img/Vehicle/car.png", 0, 0, 250, 300, 0.75, Vector2f(0.f, 650.f), 1, -1){}

void Car::update(RenderTarget& target) {
	Vehicle::updateMovement();
	
	if (getPosition().x <= -currentFrame.width) {
		setPosition(target.getSize().x, getPosition().y);
	}
}