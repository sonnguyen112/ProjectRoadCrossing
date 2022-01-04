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
#include "Vehicle.h"
#include <string>
using namespace sf;
using namespace std;

class Car : public Vehicle {
public:
	Car();
	void update(RenderTarget& target);
};