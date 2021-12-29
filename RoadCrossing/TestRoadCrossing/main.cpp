#include <iostream>
#include "Game.h"
#include "MainMenu.h"
using namespace std;

int main() {
	//Music
	Music music;
	music.openFromFile("BGM//Mario Paint Music - BGM 1.wav");

	music.play();

	//game engine
	MainMenu mainMenu(945, 709);
	while (mainMenu.isRunning()) {
		mainMenu.update();
		if (mainMenu.isClickEnter()) {
			if (mainMenu.getMenuSelect() == 0) {
				Game game("new");
				game.run();
			}
			else if (mainMenu.getMenuSelect() == 1) {
				Game game("load");
				game.run();
			}
		}
		mainMenu.render();
	}
	return 0;
}