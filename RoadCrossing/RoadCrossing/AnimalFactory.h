#pragma once
#include "Animal.h"
#include "Bat.h"
#include "Dinosaur.h"

enum AnimalType {BAT, DINOSAUR};

class AnimalFactory
{
private:
	vector<Animal*> animals;
public:
	Animal* getAnimal(AnimalType animalType);
	void initAnimals(RenderTarget& target);
	void updateAnimals(RenderTarget& target);
	void renderAnimals(RenderTarget& target);
	~AnimalFactory();
};

