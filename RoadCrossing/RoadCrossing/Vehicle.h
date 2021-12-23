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

class Vehicle {
protected:
	Sprite sprite;
	Texture textureSheet;
	IntRect currentFrame;
	Clock animationTimer;
	Vector2f curPos;
	float vel;
	int direct;

	void initTexture(string fpath);
	void initSprite(int left, int top, int width, int height, 
					float scale, Vector2f beginPos, float vel_, int direct_);
	void initAnimations();
	void updateMovement();
	void updateAnimations(int top, int widthPerImage, int maxWidthImage);
public:
	Vehicle(string fpath, int left, int top, int width, int height, 
			float scale, Vector2f beginPos, float vel_, int direct_);

	virtual Vector2f getPosition();
	virtual FloatRect getGlobalBounds();

	virtual void setPosition(float x, float y);

	virtual void update(RenderTarget& target) = 0;

	virtual void render(RenderTarget& target);
};