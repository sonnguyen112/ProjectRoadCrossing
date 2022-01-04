#pragma once
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
class MainMenu
{
private:
	RenderWindow* Menu;
	Event ev;
	int menuSelect;
	Font font;
	Text mainMenu[4];
	Texture MBGTex;
	Sprite MBG;

	void initBG();
public:
	MainMenu(float weight, float height);
	int getMenuSelect();
	bool isRunning();
	bool isClickEnter();
	
	void moveUp();
	void moveDown();
	void eventListener();
	void update();
	void render();
};

