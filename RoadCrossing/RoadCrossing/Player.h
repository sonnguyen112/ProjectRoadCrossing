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

class Player{
private:
	Texture texture;
	Sprite sprite;
	float movementSpeed;

	void initTexture();
	void initSprite();
	void initVariable();
public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	void UpdateInput();
	void update(RenderTarget* TARGET);
	void render(RenderTarget* TARGET);
	void collisionWindow();
};