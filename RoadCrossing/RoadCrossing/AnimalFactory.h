#pragma once
#include "Animal.h"
#include "Bat.h"
#include "Dinosaur.h"

enum AnimalType {BAT, DINOSAUR};

class AnimalFactory
{
public:
	Animal* getAnimal(AnimalType animalType);
};

