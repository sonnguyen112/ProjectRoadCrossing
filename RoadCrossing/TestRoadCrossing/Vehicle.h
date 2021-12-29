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
	Vector2f curPos;
	float vel;
	int direct;

	void initTexture(string fpath);
	void initSprite(
		float scale, Vector2f beginPos, float vel_, int direct_);
	void updateMovement();
public:
	Vehicle(string fpath,
		float scale, Vector2f beginPos, float vel_, int direct_);

	virtual Vector2f getPosition();
	virtual FloatRect getGlobalBounds();
	virtual float getVel();

	virtual void setPosition(float x, float y);
	virtual void setVel(float vel);

	virtual void update(RenderTarget& target) = 0;

	virtual void render(RenderTarget& target);
};