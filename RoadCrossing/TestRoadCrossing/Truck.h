#pragma once
#include "Vehicle.h"
class Truck : public Vehicle
{
private:
	Texture texture;
	Sprite sprite;

	float veclocity;

	void initVariable();
	void initTexture();
	void initSprite(float posX, float posY);
public:
	Truck(float posX, float posY);
	FloatRect getBound();
	void updateMove();
	void update();
	void render(RenderTarget* target);
};

