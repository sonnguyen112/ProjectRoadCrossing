#include <iostream>
#include "Game.h"
using namespace std;

int main() {

	//game engine
	Game game;

	//Game loop
	while (game.isRunning())
	{
		//Update
		game.update();

		//Render
		game.render();

	}
	return 0;
}