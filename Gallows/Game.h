#pragma once
#include "GameWord.h"
#include "Login.h"
#include "GameWordsBuilder.h"
#include "IGameView.h"
#include "WordsManager.h"
#include <fstream>
#include <iostream>

class MainMenu;

class Game{
private:
	MainMenu* startMenu;
	int mistakes;
	GameWordsBuilder wordsBuilder;
	std::unique_ptr<GameWord> current_word;
	std::unique_ptr<IGameView> view;
	const int MAX_MISTAKES = 6;
	int mark;
public:
	Game(std::shared_ptr<WordsManager> manager, std::unique_ptr<IGameView> view);
	~Game();
	void Start(Login& loginName);
};

