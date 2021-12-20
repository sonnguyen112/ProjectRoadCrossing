#include "AnimalFactory.h"

Animal* AnimalFactory::getAnimal(AnimalType animalType) {
	if (animalType == BAT) return new Bat();
	if (animalType == DINOSAUR) return new Dinosaur();
	return nullptr;
}