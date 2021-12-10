#include "AnimalFactory.h"

Animal* AnimalFactory::getAnimal(AnimalType animalType) {
	if (animalType == BAT) return new Bat();
	if (animalType == DINOSAUR) return new Dinosaur();
	return nullptr;
}

void AnimalFactory::initAnimals(RenderTarget& target) {
	for (int i = 0; i < 3; ++i) {
		Animal* p = getAnimal(BAT);
		float size = target.getSize().x / 3.f;
		p->setPosition(size*i, p->getPosition().y);
		animals.push_back(p);
	}

	for (int i = 0; i < 3; ++i) {
		Animal* p = getAnimal(DINOSAUR);
		float size = target.getSize().x / 3.f;
		p->setPosition(size*i, p->getPosition().y);
		animals.push_back(p);
	}
}
void AnimalFactory::updateAnimals(RenderTarget& target) {
	for(auto animal : animals) {
		animal->update();
		if (animal->getPosition().x >= target.getSize().x) {
			animal->setPosition(0, animal->getPosition().y);
		}
	}
}
void AnimalFactory::renderAnimals(RenderTarget& target) {
	for (auto animal : animals) {
		animal->render(target);
	}
}

AnimalFactory::~AnimalFactory() {
	for (auto animal : animals) {
		delete animal;
	}
}