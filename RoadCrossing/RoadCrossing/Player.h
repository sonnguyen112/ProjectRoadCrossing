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

class Player
{
private:
	Texture texture;
	Sprite sprite;
	int mX, mY;
	bool mState; //Trang thai song chet
	
	void initTexture();
	void initSprite();
public:
	Player();

	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	void update();
	void render();
};

