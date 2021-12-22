#pragma once
#include "Player.h"
#include "VehicleFactory.h"
#include "AnimalFactory.h"
#include <vector>
using namespace sf;
using namespace std;
class Game
{
private:
	//variable, window
	RenderWindow* window;
	Event ev;
	VideoMode videoMode;
	Texture GameBackgroundtex;
	Sprite GameBackground;
	int maxVehicle;
	int vehicleSpawnTime;
	int vehicleSpawnTimeMax;
	int maxAnimal;
	int animalSpawnTime;
	int animalSpawnTimeMax;

	//Object
	Player* player;
	vector<Vehicle*> vehicles;
	vector<Animal*> animals;
	AnimalFactory factory;

	//logic
	bool endGame;

	//private function
	void initVariable();
	void initWindow();
	void initPlayer();
	void initWorld();
	void initAnimals(RenderTarget& target);
public:
	// con/destructor
	Game();
	virtual ~Game();

	//checker
	bool isRunning();
	
	//function
	void eventListener();
	void spawnVehicle();
	void updateColWindow();
	void updateColVehicle();
	void updateAnimals(RenderTarget& target);
	void updateColAnimal();
	void updateVehicle();
	void update();
	void renderVehicle();
	void renderAnimals(RenderTarget& target);
	void renderBackground();
	void render();
	void run();
};

