#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <fstream>
using namespace sf;
using namespace std;
class MainMenu
{
private:
	RenderWindow* Menu;
	Event evMenu;
	int menuSelect;
	Font font;
	Text mainMenu[4];

	//Choose name when start
	Text namePlayer;
	string namePlayerText;
	Text titleNamePlayer;
	bool isNameAfter;
	void initNamePlayer();

	Texture MBGTex;
	Sprite MBG;

	void initBG();
public:
	MainMenu(float weight, float height);
	int getMenuSelect();
	string getNamePlayer();
	bool isRunning();
	bool isClickEnter();
	bool is_file_exist(const char *fileName);
	
	void moveUp();
	void moveDown();
	void eventListener();
	void update();
	void render();
	void renderNamePlayer();
};

