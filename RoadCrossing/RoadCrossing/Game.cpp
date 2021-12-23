#include "Game.h"

void Game::initVariable()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode = VideoMode(1200, 900);
	this->window = new RenderWindow(this->videoMode, "Game 1", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(60);
}
void Game::initWorld()
{
	this->GameBackgroundtex.loadFromFile("img/Vehicle/Background.jpg");
	this->GameBackground.setTexture(GameBackgroundtex);
}

Game::Game()
{
	this->initVariable();
	this->initWindow();
	this->initWorld();
	
	
	initVehicles(*window);
}

Game::~Game()
{
	delete this->window;

	for (auto vehicle : vehicles) {
		delete vehicle;
	}
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

void Game::update()
{
	this->eventListener();
	updateVehicles(*window);
	
}

void Game::render()
{
	//Clear old frame
	this->window->clear(Color::Black);
	this->renderBackground();
	
	
	
	renderVehicles(*window);
	//Display
	this->window->display();
}


void Game::initVehicles(RenderTarget& target) {
	for (int i = 0; i < 3; ++i) {
		Vehicle* p = factory.getVehicle(CAR);
		float size = target.getSize().x / 3.f;
		p->setPosition(size*i, p->getPosition().y);
		vehicles.push_back(p);
	}

	for (int i = 0; i < 3; ++i) {
		Vehicle* p = factory.getVehicle(TRUCK);
		float size = target.getSize().x / 3.f;
		p->setPosition(size*i, p->getPosition().y);
		vehicles.push_back(p);
	}
}
void Game::updateVehicles(RenderTarget& target) {
	for (auto vehicle : vehicles) {
		vehicle->update(target);
	}
}
void Game::renderVehicles(RenderTarget& target) {
	for (auto vehicle : vehicles) {
		vehicle->render(target);
	}
}
void Game::renderBackground()
{
	this->window->draw(this->GameBackground);
}