#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Player.h"

using namespace sf;
using namespace std;
class Game
{
private:
	//variable, window
	RenderWindow* window;
	Event ev;
	VideoMode videoMode;
	Player* player;
	Texture GameBackgroundtex;
	Sprite GameBackground;

	//private function
	void initVariable();
	void initWindow();
	void initPlayer();
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
