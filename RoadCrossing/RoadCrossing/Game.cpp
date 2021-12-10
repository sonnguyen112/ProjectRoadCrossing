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
	factory.initAnimals(*window);
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

void Game::update()
{
	this->eventListener();
	factory.updateAnimals(*window);
}

void Game::render()
{
	//Clear old frame
	this->window->clear(Color::Black);

	factory.renderAnimals(*window);

	//Display
	this->window->display();
}


