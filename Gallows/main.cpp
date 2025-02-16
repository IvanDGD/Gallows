#include <iostream>
#include "ConsolGameView.h"
#include "WordsManager.h"
#include "Game.h"

int main() {
	srand(time(0));
    WordsManager manager;

	ConsolGameView consoleView;

	Game game(std::make_shared<WordsManager>(manager), std::make_unique<ConsolGameView>(consoleView));
	game.Start();

	return 0;
}