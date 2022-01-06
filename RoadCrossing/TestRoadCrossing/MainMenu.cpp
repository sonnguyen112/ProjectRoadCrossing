#include "MainMenu.h"

void MainMenu::initBG()
{
	this->MBGTex.loadFromFile("BACKGROUND//1.jpg");
	this->MBG.setTexture(MBGTex);
}

void MainMenu::initNamePlayer()
{
	this->titleNamePlayer.setFont(this->font);
	this->titleNamePlayer.setCharacterSize(50);
	this->titleNamePlayer.setFillColor(Color::White);
	this->titleNamePlayer.setPosition(150, 300);
	this->titleNamePlayer.setString("Please input name player: ");
	this->namePlayer.setFont(this->font);
	this->namePlayer.setCharacterSize(50);
	this->namePlayer.setFillColor(Color::White);
	this->namePlayer.setPosition(150, 400);
	this->namePlayerText = "";
	this->namePlayer.setString(this->namePlayerText);
	this->isNameAfter = false;
}

MainMenu::MainMenu(float weight, float height)
{
	//Background
	this->initBG();
	this->initNamePlayer();
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
	this->mainMenu[2].setString("Quit");
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
	this->Menu->draw(this->MBG);
	if (this->isNameAfter == false) {
		this->renderNamePlayer();
	}
	else {
		for (int i = 0; i < 4; i++) {
			this->Menu->draw(this->mainMenu[i]);
		}
	}
	this->Menu->display();
}

void MainMenu::renderNamePlayer()
{
	this->Menu->draw(this->titleNamePlayer);
	this->Menu->draw(this->namePlayer);
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
	while (this->Menu->pollEvent(this->evMenu)) {
		if (this->evMenu.type == Event::Closed) {
			this->Menu->close();
		}
		if (this->evMenu.type == Event::KeyReleased) {
			if (this->evMenu.key.code == Keyboard::Up) {
				this->moveUp();
				break;
			}
			if (this->evMenu.key.code == Keyboard::Down) {
				this->moveDown();
				break;
			}
		}
		if (this->isNameAfter == false){
			if (this->evMenu.type == Event::TextEntered) {
				if (evMenu.text.unicode == 8) {
					if (this->namePlayerText.size() > 0) {
						this->namePlayerText.pop_back();
					}
				}
				else if (evMenu.text.unicode < 128) {
					this->namePlayerText += evMenu.text.unicode;
				}
				if (evMenu.text.unicode == 13) {
					this->isNameAfter = true;
				}
				this->namePlayer.setString(this->namePlayerText);
				break;
			}
		}
	}
}

int MainMenu::getMenuSelect()
{
	return this->menuSelect;
}


string MainMenu::getNamePlayer()
{
	return this->namePlayerText;
}

bool MainMenu::isRunning()
{
	return this->Menu->isOpen();
}

bool MainMenu::isClickEnter()
{
	return this->evMenu.type == Event::KeyReleased && this->evMenu.key.code == Keyboard::Return;
}

bool MainMenu::is_file_exist(const char * fileName)
{
	ifstream infile(fileName);
	return infile.good();
}
