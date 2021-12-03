#pragma once
//interface
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;

enum VehicleType
{
	CAR,
	TRUCK
};

class Vehicle
{
public:
	virtual void update() = 0;
	virtual void render(RenderTarget* target) = 0;
};

