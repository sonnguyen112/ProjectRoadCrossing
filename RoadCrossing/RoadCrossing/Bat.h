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
#include "Animal.h"
#include <string>
using namespace sf;
using namespace std;

class Bat : public Animal{
public:
	Bat();
	void update(RenderTarget& target);
};