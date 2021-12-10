#pragma once
//interface
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;

class Animal {
protected:
	Sprite sprite;
	Texture textureSheet;
	IntRect currentFrame;
	Clock animationTimer;
	Vector2f curPos;
	float vel;

	void initTexture(string fpath);
	void initSprite(int left, int top, int width, int height, 
					float scale, Vector2f beginPos, float vel_);
	void initAnimations();
	void updateMovement();
	void updateAnimations(int top, int widthPerImage, int maxWidthImage);
public:
	Animal(string fpath, int left, int top, int width, int height, 
			float scale, Vector2f beginPos, float vel_);

	virtual Vector2f getPosition();
	virtual FloatRect getGlobalBounds();

	virtual void setPosition(float x, float y);

	virtual void update() = 0;

	virtual void render(RenderTarget& target);
};