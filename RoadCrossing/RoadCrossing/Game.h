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
#include "VehicleFactory.h"
#include "Vehicle.h"
using namespace sf;
using namespace std;
class Game
{
private:
	//variable, window
	RenderWindow* window;
	Event ev;
	VideoMode videoMode;

	
	vector<Vehicle*> vehicles;
	VehicleFactory factory;
	void initVehicles(RenderTarget& target);
	void updateVehicles(RenderTarget& target);
	void renderVehicles(RenderTarget& target);	

	//private function
	void initVariable();
	void initWindow();
	Texture GameBackgroundtex;
	Sprite GameBackground;
	void initWorld();
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
	void renderBackground();   
};

