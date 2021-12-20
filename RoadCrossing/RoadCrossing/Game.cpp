#include "Game.h"

void Game::initVariable()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode = VideoMode(1200, 900);
	this->window = new RenderWindow(this->videoMode, "Game 1", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(144);
}

void Game::initPlayer()
{
	this->player = new Player(550, 1000);
}

void Game::initWorld()
{
	this->GameBackgroundtex.loadFromFile("Background.jpg");
	this->GameBackground.setTexture(GameBackgroundtex);
}

Game::Game()
{
	this->initVariable();
	this->initWindow();
	this->initPlayer();
	this->initWorld();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
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

	this->player->update(this->window);
	this->player->collisionWindow();
}

void Game::render()
{

	//Clear old frame
	this->window->clear(Color::Black);

	//World render
	this->renderBackground();

	this->player->render(this->window);
	//Display
	this->window->display();
}

void Game::renderBackground()
{
	this->window->draw(this->GameBackground);
}


