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

	//Save mes
	Texture textureSavedMes;
	Sprite savedMes;
	int timeDisplaySave;
	int timeDisplaySaveMax;
	bool isDisplaySaved;

	// Resume / Game over handling
	Text GameOverText;
	Text isResumeText;
	bool isResume = true, isGameOver = false;

	//Save when quit 
	Text askSave;
	Text isSaveText;
	bool isQuit = false;

	//logic
	bool endGame;

	//Name player
	string namePlayer;

	//den tin hieu
	Texture redLight, greenLight;
	Sprite light1;
	Sprite light2;
	int timeChangeColorMax = 300;
	float isRed = 0; //0 is false, 1 is true
	int timeChangeColor = timeChangeColorMax;
	int counter = 0;

	//private function
	void initVariable();
	void initWindow();
	void initPlayer();
	void initWorld();
	void initAnimals(RenderTarget& target);
	void initVehicles(RenderTarget& target);
	void initText();
	void initSavedMes();
	void initLight();
public:
	// con/destructor
	Game(string gameType, string namePlayer);
	virtual ~Game();

	//checker
	bool isRunning();
	void setNamePlayer(string name);
	
	//function
	void eventListener();
	void updateColWindow();
	void updateVehicles(RenderTarget& target);
	void updateAnimals(RenderTarget& target);
	void updateColAnimal();
	void updateText();
	void updateNamePlayer();
	void updateLight();
	void update();
	void renderVehicles(RenderTarget& target);
	void renderAnimals(RenderTarget& target);
	void updateColVehicle();
	void updateTimeDisplaySaved();
	void renderBackground();
	void renderText();
	void renderSavedMes();
	void renderLight();
	void render();
	void run();
	void saveGame(bool isDisplayText);
	void loadGame();
	void updateLevel();
};

