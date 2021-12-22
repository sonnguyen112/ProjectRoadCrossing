#include "Game.h"
#include "..\..\TestRoadCrossing\TestRoadCrossing\Game.h"

void Game::initVariable()
{
	this->window = nullptr;
	this->maxVehicle = 10;
	this->vehicleSpawnTimeMax = 80;
	this->vehicleSpawnTime = this->vehicleSpawnTimeMax;
	this->endGame = false;
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
	this->player->setPos(500, 1100);
}

void Game::initAnimals(RenderTarget& target) {
	for (int i = 0; i < 3; ++i) {
		Animal* p = factory.getAnimal(BAT);
		float size = target.getSize().x / 3.f;
		p->setPosition(size*i, p->getPosition().y);
		animals.push_back(p);
	}

	for (int i = 0; i < 3; ++i) {
		Animal* p = factory.getAnimal(DINOSAUR);
		float size = target.getSize().x / 3.f;
		p->setPosition(size*i, p->getPosition().y);
		animals.push_back(p);
	}
}

void Game::initWorld()
{
	this->GameBackgroundtex.loadFromFile("PlayerImage//Background.jpg");
	this->GameBackground.setTexture(GameBackgroundtex);
}


void Game::spawnVehicle()
{
	if (this->vehicles.size() <= this->maxVehicle) {
		if (this->vehicleSpawnTime >= this->vehicleSpawnTimeMax) {
			this->vehicleSpawnTime = 0;
			this->vehicles.push_back(VehicleFactory::getVehicle(CAR,  -30, this->window->getSize().y / 2));
			this->vehicles.push_back(VehicleFactory::getVehicle(TRUCK, -30,  this->window->getSize().y / 2 - 400));
		}
		else {
			this->vehicleSpawnTime++;
		}
	}
}

Game::Game()
{	
	this->initVariable();
	this->initWindow();
	this->initPlayer();
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
}

void Game::updateColVehicle()
{
	for (auto e : this->vehicles) {
		if (this->player->getBound().intersects(e->getBound())) {
			this->endGame = true;
			break;
		}
	}
}

void Game::updateColAnimal()
{
	for (auto e : this->animals) {
		if (this->player->getBound().intersects(e->getGlobalBounds())){
			this->endGame = true;
			break;
		}
	}
}

void Game::updateVehicle()
{
	this->spawnVehicle();
	
	for (int i = 0; i < this->vehicles.size(); i++) {
		this->vehicles[i]->update();
	}

	for (int i = 0; i < this->vehicles.size(); i++) {
		if (this->vehicles[i]->getBound().left > this->window->getSize().x) {
			this->vehicles.erase(this->vehicles.begin() + i);
		}
	}
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
		this->player->update();
		this->updateColWindow();
		//this->updateVehicle();
		//this->updateColVehicle();
		updateAnimals(*window);
		this->updateColAnimal();
	}
}

void Game::renderVehicle()
{
	for (int i = 0; i < this->vehicles.size(); i++) {
		this->vehicles[i]->render(this->window);
	}
}

void Game::renderAnimals(RenderTarget& target) {
	for (auto animal : animals) {
		animal->render(target);
	}
}

void Game::renderBackground()
{
	this->window->draw(this->GameBackground);
}

void Game::render()
{
	//Clear old frame
	this->window->clear(Color::Black);

	//Draw background
	this->renderBackground();

	//draw player
	this->player->render(this->window);

	//draw vehicle
	//this->renderVehicle();

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


