#include <iostream>
#include "Game.h"
#include "MainMenu.h"
using namespace std;

int main() {

	//game engine
	MainMenu mainMenu(945, 709);
	while (mainMenu.isRunning()) {
		mainMenu.update();
		if (mainMenu.isClickEnter()) {
			if (mainMenu.getMenuSelect() == 0) {
				Game game;
				game.run();
			}
		}
		mainMenu.render();
	}
	return 0;
}