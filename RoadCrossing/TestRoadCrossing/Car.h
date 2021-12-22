#pragma once
#include "Vehicle.h"
class Car: public Vehicle
{
private:
	Texture texture;
	Sprite sprite;

	float veclocity;

	void initVariable();
	void initTexture();
	void initSprite(float posX, float posY);
public:
	Car(float posX, float posY);
	FloatRect getBound();
	void updateMove();
	void update();
	void render(RenderTarget* target);
};

