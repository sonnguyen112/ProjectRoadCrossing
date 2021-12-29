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
	SoundBuffer buffer;
	Sound sound;
	float vel;
	int direct;

	void initTexture(string fpath);
	void initSprite(int left, int top, int width, int height,
		float scale, Vector2f beginPos, float vel_, int direct_);
	void initAnimations();
	void updateMovement();
	void updateAnimations(int top, int widthPerImage, int maxWidthImage);

	void initSoundBuffer(string fpath);
public:
	Animal(string fpath_image, string fpath_sound, int left, int top, int width, int height,
		float scale, Vector2f beginPos, float vel_, int direct_);

	virtual void playSound();

	virtual Vector2f getPosition();
	virtual FloatRect getGlobalBounds();
	virtual float getVel();
	virtual void setVel(float vel);

	virtual void setPosition(float x, float y);

	virtual void update(RenderTarget& target) = 0;

	virtual void render(RenderTarget& target);
};