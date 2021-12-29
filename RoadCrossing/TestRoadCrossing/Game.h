#pragma once
#include "Player.h"
#include "VehicleFactory.h"
#include "AnimalFactory.h"
#include <vector>
#include <fstream>
#include <sstream>
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
	string gameType = "new";
	vector<float> saved_data;

	//Object
	Player* player;
	vector<Vehicle*> vehicles;
	vector<Animal*> animals;
	AnimalFactory factory;
	VehicleFactory v_factory;
	Font font;
	Text pointText;
	int point;
	Text levelText;
	int level;
	Text GameOverText;

	//logic
	bool endGame;

	//private function
	void initGameOverText();
	void initVariable();
	void initWindow();
	void initPlayer();
	void initWorld();
	void initAnimals(RenderTarget& target);
	void initVehicles(RenderTarget& target);
	void initText();
public:
	// con/destructor
	Game(string gameType);
	virtual ~Game();

	//checker
	bool isRunning();
	
	//function
	void eventListener();
	void updateColWindow();
	void updateVehicles(RenderTarget& target);
	void updateAnimals(RenderTarget& target);
	void updateColAnimal();
	void updateText();
	void update();
	void renderVehicles(RenderTarget& target);
	void renderAnimals(RenderTarget& target);
	void updateColVehicle();
	void renderBackground();
	void renderText();
	void render();
	void run();
	void saveGame();
	void loadGame();
	void updateLevel();
};

