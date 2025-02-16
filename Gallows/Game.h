#pragma once
#include "GameWord.h"
#include "GameWordsBuilder.h"
#include "IGameView.h"
#include <memory>

using std::unique_ptr;

class Game
{
private:
	unique_ptr<GameWord> current_word;
	int mistakes;
	GameWordsBuilder wordsBuilder;
	unique_ptr<IGameView> view;
	const int MAX_MISTAKES = 6;
public:
	Game(shared_ptr<WordsManager> manager, 
		unique_ptr<IGameView> view)
		: wordsBuilder(manager), 
		view(std::move(view))
	{
		mistakes = 0;
	}
	~Game() {

	}
	void Start()
	{
		do 
		{
			current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
			view->DisplayWord(current_word->GetExternalWord());
			view->DisplayMistakes(mistakes);
			while (!current_word->isGuessed() && mistakes < MAX_MISTAKES)
			{
				char letter = view->GetInputLetter();
				if (!current_word->InputLetter(letter))
					++mistakes;
					
					view->DisplayWord(current_word->GetExternalWord());
				view->DisplayMistakes(mistakes);
			}
			if (mistakes < MAX_MISTAKES)
			{
				view->WordGuessed();
			}
			else {
				view->GameOver();
				break;
			}
		} while (view->IsGameContinue());
	}
	void Save() {
		std::ofstream file("Saves.txt", std::ios::out);
		if (file.is_open())
		{
			file << mistakes << "\n";
			file << current_word->GetExternalWord() << "\n";
			file.close();
		}
	}
	void Load() {
		std::ifstream file("Saves.txt", std::ios::in);
		if (file.is_open())
		{
			std::string saved_word;
			file >> mistakes;
			file.ignore();
			std::getline(file, saved_word);
			file.close();

			current_word = std::make_unique<GameWord>(saved_word);
			view->DisplayWord(current_word->GetExternalWord());
			view->DisplayMistakes(mistakes);
		}
	}
};

