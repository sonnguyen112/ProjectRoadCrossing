#include "Game.h"

void Game::initVariable()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode = VideoMode(800, 600);
	this->window = new RenderWindow(this->videoMode, "Game 1", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(144);
}

Game::Game()
{
	this->initVariable();
	this->initWindow();
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
}

void Game::render()
{
	//Clear old frame
	this->window->clear(Color::Black);

	//Display
	this->window->display();
}


