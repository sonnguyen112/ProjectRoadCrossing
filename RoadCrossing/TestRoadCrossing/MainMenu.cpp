#include "MainMenu.h"

MainMenu::MainMenu(float weight, float height)
{
	this->Menu = new RenderWindow(VideoMode(weight, height), "Main Menu", Style::Titlebar | Style::Close);
	if (!this->font.loadFromFile("font//ELEPHNT.ttf")) {
		cout << "Error font";
	}
	//New game
	this->mainMenu[0].setFont(this->font);
	this->mainMenu[0].setFillColor(Color::White);
	this->mainMenu[0].setString("New Game");
	this->mainMenu[0].setCharacterSize(70);
	this->mainMenu[0].setPosition(300, 200);
	//Load game
	this->mainMenu[1].setFont(this->font);
	this->mainMenu[1].setFillColor(Color::White);
	this->mainMenu[1].setString("Load Game");
	this->mainMenu[1].setCharacterSize(70);
	this->mainMenu[1].setPosition(300, 300);
	//Setting
	this->mainMenu[2].setFont(this->font);
	this->mainMenu[2].setFillColor(Color::White);
	this->mainMenu[2].setString("Setting");
	this->mainMenu[2].setCharacterSize(70);
	this->mainMenu[2].setPosition(300, 400);

	this->menuSelect = -1;
}

void MainMenu::update()
{
	this->eventListener();
}

void MainMenu::render()
{
	this->Menu->clear(Color::Black);
	for (int i = 0; i < 4; i++) {
		this->Menu->draw(this->mainMenu[i]);
	}
	this->Menu->display();
}

void MainMenu::moveUp()
{
	if (this->menuSelect - 1 >= 0) {
		this->mainMenu[this->menuSelect].setFillColor(Color::White);

		this->menuSelect--;
		if (this->menuSelect == -1) {
			this->menuSelect = 2;
		}
		this->mainMenu[this->menuSelect].setFillColor(Color::Blue);
	}
}

void MainMenu::moveDown()
{
	if (this->menuSelect + 1 <= 2) {
		this->mainMenu[this->menuSelect].setFillColor(Color::White);


		this->menuSelect++;
		if (this->menuSelect == 3) {
			this->menuSelect = 0;
		}
		this->mainMenu[this->menuSelect].setFillColor(Color::Blue);
	}
}

void MainMenu::eventListener()
{
	while (this->Menu->pollEvent(this->ev)) {
		if (this->ev.type == Event::Closed) {
			this->Menu->close();
		}
		if (this->ev.type == Event::KeyReleased) {
			if (this->ev.key.code == Keyboard::Up) {
				this->moveUp();
				break;
			}
			if (this->ev.key.code == Keyboard::Down) {
				this->moveDown();
				break;
			}
		}
	}
}

int MainMenu::getMenuSelect()
{
	return this->menuSelect;
}

bool MainMenu::isRunning()
{
	return this->Menu->isOpen();
}

bool MainMenu::isClickEnter()
{
	return this->ev.type == Event::KeyReleased && this->ev.key.code == Keyboard::Return;
}
