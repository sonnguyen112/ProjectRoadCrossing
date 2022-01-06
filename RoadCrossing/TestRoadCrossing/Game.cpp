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
	this->pointText.setCharacterSize(40);
	this->pointText.setPosition(0, 22);
	this->levelText.setFont(this->font);
	this->levelText.setFillColor(Color::Red);
	this->levelText.setString("Level: " + to_string(this->level));
	this->levelText.setCharacterSize(40);
	this->levelText.setPosition(770,22);

	//Init game over text
	this->GameOverText.setFont(this->font);
	this->GameOverText.setFillColor(Color::Black);
	this->GameOverText.setString("Game Over");
	this->GameOverText.setCharacterSize(80);
	this->GameOverText.setPosition(260, 200);

	//Init game over handling text
	this->isResumeText.setFont(this->font);
	this->isResumeText.setFillColor(Color::Black);
	this->isResumeText.setString("Resume Y or N ?");
	this->isResumeText.setCharacterSize(50);
	this->isResumeText.setPosition(270, 300);

	//init ask saved text
	this->askSave.setFont(this->font);
	this->askSave.setFillColor(Color::Black);
	this->askSave.setString("Do you want Save Game ?");
	this->askSave.setCharacterSize(70);
	this->askSave.setPosition(20, 200);

	//Init asksaved handling text
	this->isSaveText.setFont(this->font);
	this->isSaveText.setFillColor(Color::Black);
	this->isSaveText.setString("Y or N ?");
	this->isSaveText.setCharacterSize(50);
	this->isSaveText.setPosition(380, 300);
}

void Game::initSavedMes()
{
	if (!this->textureSavedMes.loadFromFile("texture//saved.jpg")) {
		cout << "Error saved";
	}
	this->savedMes.setTexture(this->textureSavedMes);
	this->savedMes.scale(0.4, 0.4);
	this->savedMes.setPosition(280, 250);
	this->timeDisplaySaveMax = 50;
	this->timeDisplaySave = 0;
	this->isDisplaySaved = false;
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


Game::Game(string gameType, string namePlayer)
{	
	this->setNamePlayer(namePlayer);
	this->gameType = gameType;
	if (gameType == "load") {
		this->loadGame();
	}
	this->initVariable();
	this->initWindow();
	this->initPlayer();
	this->initLight();
	this->initSound();
	this->initText();
	this->initSavedMes();
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

void Game::setNamePlayer(string name)
{
	this->namePlayer = name;
	this->namePlayer.pop_back();
	cout << this->namePlayer;
}

void Game::eventListener()
{
	//Event Listening
	while (this->window->pollEvent(ev))
	{
		switch (ev.type) {
		case Event::Closed:
			this->endGame = true;
			this->isQuit = true;
			break;
		case Event::KeyPressed:
			if (ev.key.code == Keyboard::Escape) {
				this->endGame = true;
				this->isQuit = true;
			}
			else if (ev.key.code == Keyboard::L) {
				saveGame(true);
			}
			if (ev.key.code == Keyboard::Y && endGame) {
				if (isGameOver) { // reset the position only when game is over
					isGameOver = false;
					player->setPos(500, 1100);
					player->PlayerCol(0.f);
				}
				if (this->isQuit) {
					this->saveGame(true);
					this->window->close();
				}
				endGame = false;
			}
			if (ev.key.code == Keyboard::N && endGame) {
				if (this->isQuit) {
					this->window->close();
				}
				isResume = false;
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
		if (this->isRed == 0) {
			vehicle->update(target);
		}
	}
}

void Game::updateColAnimal()
{
	for (auto e : this->animals) {
		if (e->getGlobalBounds().contains(this->player->getMidPoint())){
			this->player->PlayerCol(90);
			e->playSound();
			this->endGame = true;
			this->isGameOver = true;
			break;
		}
	}
}

void Game::updateText()
{
	this->pointText.setString("Point: " + to_string(this->point));
	this->levelText.setString("Level: " + to_string(this->level));
}

void Game::updateNamePlayer()
{
	
}

void Game::updateLight()
{
	if (this->timeChangeColor <= 0) {
		if (counter % 2 == 0) {
			this->light1.setTexture(this->redLight);
			this->light2.setTexture(this->redLight);
			this->isRed = 1;
		}
		else {
			this->light1.setTexture(this->greenLight);
			this->light2.setTexture(this->greenLight);
			this->isRed = 0;
		}
		this->timeChangeColor = this->timeChangeColorMax;
		counter++;
	}
	else {
		this->timeChangeColor--;
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
		this->updateText();
		this->updateTimeDisplaySaved();
		this->updateLevel();
		this->player->update();
		this->updateLight();
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
		if (e->getGlobalBounds().contains(this->player->getMidPoint())) {
			this->player->PlayerCol(90);
			e->playSound();
			this->endGame = true;
			this->isGameOver = true;
			break;
		}
	}
}

void Game::updateTimeDisplaySaved()
{
	if (this->timeDisplaySave >= this->timeDisplaySaveMax) {
		this->timeDisplaySave = 0;
		this->isDisplaySaved = false;
	};
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

void Game::renderSavedMes()
{
	if (this->timeDisplaySave <= this->timeDisplaySaveMax && this->isDisplaySaved) {
		this->window->draw(this->savedMes);
		this->timeDisplaySave++;
	}
}

void Game::renderLight()
{
	window->draw(this->light1);
	window->draw(this->light2);
}


void Game::render()
{
	//Clear old frame
	this->window->clear(Color::Black);

	//Draw background
	this->renderBackground();

	//draw player
	this->player->render(this->window);

	//draw Light
	this->renderLight();

	//draw text
	this->renderText();

	//draw vehicle
	renderVehicles(*window);

	//Draw animal
	renderAnimals(*window);

	//Draw Game Over / Resume
	if (isGameOver) {
		window->draw(GameOverText);
		window->draw(isResumeText);
	}

	//Draw AskSave
	if (isQuit) {
		window->draw(this->askSave);
		window->draw(this->isSaveText);
	}

	//Draw save Mes
	this->renderSavedMes();

	//Display
	this->window->display();
}

void Game::run()
{
	this->saveGame(false);
	//Game loop
	while (this->isRunning())
	{
		//Update
		this->update();

		if (!isResume) return;

		//Render
		this->render();

	}
}

void Game::saveGame(bool isDisplayText)
{
	if (isDisplayText) {
		this->isDisplaySaved = true;
	}
	string savepath = this->namePlayer + ".txt";
	ofstream saveFile(savepath);
	if (saveFile.is_open()) {
		saveFile << this->player->getBound().left << " " << this->player->getBound().top << " ";
		for (int i = 0; i < 6; i++) {
			saveFile << this->animals[i]->getGlobalBounds().left << " " << this->animals[i]->getGlobalBounds().top << " ";
		}
		for (int i = 0; i < 6; i++) {
			saveFile << this->vehicles[i]->getGlobalBounds().left << " " << this->vehicles[i]->getGlobalBounds().top << " ";
		}
		saveFile << this->player->getVel() << " " << this->animals[0]->getVel() << " " << this->vehicles[0]->getVel() << " " << this->point << " " << this->level << " " << this->isRed;
	}
	else {
		cout << "Error";
	}
	saveFile.close();
}

void Game::loadGame()
{
	this->saved_data = {};
	string data;
	string savepath = this->namePlayer + ".txt";
	ifstream saveFile(savepath);
	if (saveFile.is_open()) {
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
	else {
		cout << "Error";
	}
}

void Game::updateLevel()
{
	if (this->player->getBound().top <= 10) {
		this->levelUpSound.play();
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

void Game::initLight()
{
	this->redLight.loadFromFile("texture//red.png");
	this->greenLight.loadFromFile("texture//green.png");
	if (this->gameType == "load") {
		if (this->saved_data[this->saved_data.size() - 1] == 0) {
			this->light1.setTexture(this->greenLight);
			this->light2.setTexture(this->greenLight);
			this->isRed = 0;
		}
		else {
			this->light1.setTexture(this->redLight);
			this->light2.setTexture(this->redLight);
			this->isRed = 1;
		}
	}
	else {
		this->isRed = 0;
		this->light1.setTexture(this->greenLight);
		this->light2.setTexture(this->greenLight);
	}
	this->light1.setPosition(0, 310);
	this->light2.setPosition(910, 450);
	this->light1.scale(0.2, 0.2);
	this->light2.scale(0.2, 0.2);
}

void Game::initSound()
{
	this->levelUpBuffer.loadFromFile("sound//ting.flac");
	this->levelUpSound.setBuffer(this->levelUpBuffer);
}


