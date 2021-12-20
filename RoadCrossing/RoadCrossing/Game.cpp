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

Game::Game()
{
	this->initVariable();
	this->initWindow();
	initAnimals(*window);
}

Game::~Game()
{
	delete this->window;

	for (auto animal : animals) {
		delete animal;
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
	updateAnimals(*window);
}

void Game::render()
{
	//Clear old frame
	this->window->clear(Color::Black);

	renderAnimals(*window);

	//Display
	this->window->display();
}

//____________________Animals____________________
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
void Game::updateAnimals(RenderTarget& target) {
	for (auto animal : animals) {
		animal->update(target);
	}
}
void Game::renderAnimals(RenderTarget& target) {
	for (auto animal : animals) {
		animal->render(target);
	}
}
