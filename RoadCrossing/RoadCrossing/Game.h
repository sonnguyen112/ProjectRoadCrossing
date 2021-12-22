#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
//test
#include "AnimalFactory.h"
#include "Animal.h"
using namespace sf;
using namespace std;
class Game
{
private:
	//variable, window
	RenderWindow* window;
	Event ev;
	VideoMode videoMode;

	//Animals
	vector<Animal*> animals;
	AnimalFactory factory;
	void initAnimals(RenderTarget& target);
	void updateAnimals(RenderTarget& target);
	void renderAnimals(RenderTarget& target);	

	//private function
	void initVariable();
	void initWindow();
public:
	// con/destructor
	Game();
	virtual ~Game();

	//checker
	bool isRunning();

	//function
	void eventListener();
	void update();
	void render();
};
