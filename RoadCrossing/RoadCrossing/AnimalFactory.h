#pragma once
#include "Animal.h"
class AnimalFactory
{
public:
	Animal* getAnimal(AnimalType animalType);
};

