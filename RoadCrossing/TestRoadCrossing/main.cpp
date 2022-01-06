#include <iostream>
#include "Game.h"
#include "MainMenu.h"
using namespace std;

int main() {
	//Music
	Music music;
	music.openFromFile("BGM//Mario Paint Music - BGM 1.wav");
	music.setVolume(20);

	music.play();

	//game engine
	MainMenu mainMenu(945, 709);
	while (mainMenu.isRunning()) {
		mainMenu.update();
		if (mainMenu.isClickEnter()) {
			if (mainMenu.getMenuSelect() == 0) {
				Game game("new", mainMenu.getNamePlayer());
				game.run();
			}
			else if (mainMenu.getMenuSelect() == 1) {
				string name = mainMenu.getNamePlayer();
				name.pop_back();
				if (mainMenu.is_file_exist((name + ".txt").c_str())) {
					Game game("load", mainMenu.getNamePlayer());
					game.run();
				}
			}
			else if (mainMenu.getMenuSelect() == 2) {
				break;
			}
		}
		mainMenu.render();
	}
	return 0;
}