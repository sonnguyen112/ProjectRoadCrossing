#include "Game.h"
#include "..\..\TestRoadCrossing\TestRoadCrossing\Game.h"

void Game::initVehicles(RenderTarget & target)
{
	int temp = 14;
	for (int i = 0; i < 3; ++i) {
		Vehicle* p = v_factory.getVehicle(CAR);
		if (this->gameType == "new") {
			float size = target.getSize().x / 3.f;
			p->setPosition(size*i, p->getPosition().y);
			vehicles.push_back(p);
		}
		else {
			p->setPosition(this->saved_data[temp], this->saved_data[temp + 1]);
			p->setVel(this->saved_data[28]);
			vehicles.push_back(p);
			temp += 2;
		}
	}

	for (int i = 0; i < 3; ++i) {
		Vehicle* p = v_factory.getVehicle(TRUCK);
		if (this->gameType == "new") {
			float size = target.getSize().x / 3.f;
			p->setPosition(size*i, p->getPosition().y);
			vehicles.push_back(p);
		}
		else {
			p->setPosition(this->saved_data[temp], this->saved_data[temp + 1]);
			p->setVel(this->saved_data[28]);
			vehicles.push_back(p);
			temp += 2;
		}
	}
}

void Game::initText()
{
	if (!this->font.loadFromFile("font//ELEPHNT.ttf")) {
		cout << "Error font";
	}
	this->pointText.setFont(this->font);
	this->pointText.setFillColor(Color::Red);
	this->pointText.setString("Point: " + to_string(this->point));
	this->pointText.setCharacterSize(30);
	this->pointText.setPosition(0, 20);
	this->levelText.setFont(this->font);
	this->levelText.setFillColor(Color::Red);
	this->levelText.setString("Level: " + to_string(this->level));
	this->levelText.setCharacterSize(30);
	this->levelText.setPosition(820, 20);
}

void Game::initVariable()
{
	this->window = nullptr;
	this->endGame = false;
	if (this->gameType == "new") {
		this->point = 0;
		this->level = 1;
	}
	else {
		this->point = this->saved_data[29];
		this->level = this->saved_data[28];
	}
}

void Game::initWindow()
{
	this->videoMode.width = 945;
	this->videoMode.height = 709;
	this->window = new RenderWindow(this->videoMode, "Game 1", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initPlayer()
{
	this->player = new Player();
	if (this->gameType == "new") {
		this->player->setPos(500, 1100);
	}
	else {
		this->player->setVel(this->saved_data[26]);
		cout << this->saved_data[26];
		this->player->setPos(this->saved_data[0], this->saved_data[1]);
	}
}

void Game::initAnimals(RenderTarget& target) {
	int temp = 2;
	for (int i = 0; i < 3; ++i) {
		Animal* p = factory.getAnimal(BAT);
		if (this->gameType == "new") {
			float size = target.getSize().x / 3.f;
			p->setPosition(size*i, p->getPosition().y);
			animals.push_back(p);
		}
		else {
			p->setPosition(this->saved_data[temp], this->saved_data[temp + 1]);
			p->setVel(this->saved_data[27]);
			animals.push_back(p);
			temp += 2;
		}
	}

	for (int i = 0; i < 3; ++i) {
		Animal* p = factory.getAnimal(DINOSAUR);
		if (this->gameType == "new") {
			float size = target.getSize().x / 3.f;
			p->setPosition(size*i, p->getPosition().y);
			animals.push_back(p);
		}
		else {
			p->setPosition(this->saved_data[temp], this->saved_data[temp + 1]);
			p->setVel(this->saved_data[27]);
			animals.push_back(p);
			temp += 2;
		}
	}
}

void Game::initWorld()
{
	this->GameBackgroundtex.loadFromFile("PlayerImage//Background.jpg");
	this->GameBackground.setTexture(GameBackgroundtex);
}


Game::Game(string gameType)
{	
	this->gameType = gameType;
	if (gameType == "load") {
		this->loadGame();
	}
	this->initVariable();
	this->initWindow();
	this->initPlayer();
	this->initText();
	initVehicles(*window);
	initAnimals(*window);
	this->initWorld();
}

Game::~Game()
{
	delete this->window;
}

bool Game::isRunning()
{
	return this->window->isOpen();
}

void Game::eventListener()
{
	//Event Listening
	while (this->window->pollEvent(ev))
	{
		switch (ev.type) {
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (ev.key.code == Keyboard::Escape) {
				this->window->close();
			}
			if (ev.key.code == Keyboard::L) {
				saveGame();
			}
			break;
		}
	}
}

void Game::updateColWindow()
{
	if (this->player->getBound().left <= 0) {
		this->player->setPos(0, this->player->getBound().top);
	}
	if (this->player->getBound().top <= 0) {
		this->player->setPos(this->player->getBound().left, 0);
	}
	if (this->player->getBound().top + this->player->getBound().height >= this->window->getSize().y) {
		this->player->setPos(this->player->getBound().left, this->window->getSize().y - this->player->getBound().height);
	}
	if (this->player->getBound().left + this->player->getBound().width >= this->window->getSize().x) {
		this->player->setPos(this->window->getSize().x - this->player->getBound().width, this->player->getBound().top);
	}
}

void Game::updateVehicles(RenderTarget & target)
{
	for (auto vehicle : vehicles) {
		vehicle->update(target);
	}
}

void Game::updateColAnimal()
{
	for (auto e : this->animals) {
		if (this->player->getBound().intersects(e->getGlobalBounds())){
			e->playSound();
			this->endGame = true;
			break;
		}
	}
}

void Game::updateText()
{
	this->pointText.setString("Point: " + to_string(this->point));
	this->levelText.setString("Level: " + to_string(this->level));
}

void Game::updateAnimals(RenderTarget& target) {
	for (auto animal : animals) {
		animal->update(target);
	}
}

void Game::update()
{
	this->eventListener();
	if (!this->endGame) {
		this->updateText();
		this->updateLevel();
		this->player->update();
		this->updateColWindow();
		updateVehicles(*window);
		this->updateColVehicle();
		updateAnimals(*window);
		this->updateColAnimal();
	}
}

void Game::renderVehicles(RenderTarget & target)
{
	for (auto vehicle : vehicles) {
		vehicle->render(target);
	}
}


void Game::renderAnimals(RenderTarget& target) {
	for (auto animal : animals) {
		animal->render(target);
	}
}

void Game::updateColVehicle()
{
	for (auto e : this->vehicles) {
		if (this->player->getBound().intersects(e->getGlobalBounds())) {
			this->endGame = true;
			break;
		}
	}
}

void Game::renderBackground()
{
	this->window->draw(this->GameBackground);
}

void Game::renderText()
{
	this->window->draw(this->pointText);
	this->window->draw(this->levelText);
}

void Game::render()
{
	//Clear old frame
	this->window->clear(Color::Black);

	//Draw background
	this->renderBackground();

	//draw player
	this->player->render(this->window);

	//draw text
	this->renderText();

	//draw vehicle
	renderVehicles(*window);

	//Draw animal
	renderAnimals(*window);

	//Display
	this->window->display();
}

void Game::run()
{
	//Game loop
	while (this->isRunning())
	{
		//Update
		this->update();

		//Render
		this->render();

	}
}

void Game::saveGame()
{
	ofstream saveFile("save_data.txt");
	saveFile << this->player->getBound().left << " " << this->player->getBound().top << " ";
	for (int i = 0; i < 6; i++) {
		saveFile << this->animals[i]->getGlobalBounds().left << " " << this->animals[i]->getGlobalBounds().top << " ";
	}
	for (int i = 0; i < 6; i++) {
		saveFile << this->vehicles[i]->getGlobalBounds().left << " " << this->vehicles[i]->getGlobalBounds().top << " ";
	}
	saveFile << this->player->getVel() << " " << this->animals[0]->getVel() << " " << this->vehicles[0]->getVel() << " " << this->point << " " << this->level;
	saveFile.close();
}

void Game::loadGame()
{
	this->saved_data = {};
	string data;
	ifstream saveFile("save_data.txt");
	getline(saveFile, data);
	stringstream ss(data);
	float value;
	while (ss >> value) {
		this->saved_data.push_back(value);
	}
	for (int i = 0; i < this->saved_data.size(); i++) {
		cout << this->saved_data[i] << " ";
	}
}

void Game::updateLevel()
{
	if (this->player->getBound().top <= 10) {
		this->point += 10;
		this->level += 1;
		for (int i = 0; i < 6; ++i) {
			this->vehicles[i]->setVel(this->vehicles[i]->getVel() + 1);
		}
		for (int i = 0; i < 6; ++i) {
			this->animals[i]->setVel(this->animals[i]->getVel() + 1);
		}
		this->player->setPos(500, 1100);
	}
}


