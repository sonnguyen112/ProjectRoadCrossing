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

	float veclocity;
	IntRect curFrame;
	Clock animationTimer;

	void initVariable();
	void initTexture();
	void initSprite();
public:
	Player();

	//getter
	FloatRect getBound();
	float getVel();

	//setter
	void setPos(float x, float y);
	void setVel(float vel);

	void updateCurFrame();
	void updateMove();
	void update();
	void render(RenderTarget* target);
};

