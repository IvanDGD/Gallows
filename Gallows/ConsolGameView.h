#pragma once
#include "IGameView.h"
#include <iostream>

class ConsolGameView : public IGameView
{
	int mistakes;
public:
	void DisplayWord(const std::string& word) override {
		
		for (char letter : word)
		{
			if (letter == ' ') {
				std::cout << "_ ";
			}
			else {
				std::cout << letter << ' ';
			}
			
		}
		std::cout << std::endl;
	}

	void DisplayMistakes(int mistakes) override {
		std::cout << "Mistakes: (" << mistakes << "/6)" << std::endl;
	}

	void DisplayMessage(const std::string& message) override {
		std::cout << "DisplayMessage: " << message << std::endl;
	}

	char GetInputLetter() override {
		char input;
		std::cout << "Input the letter: ";
		std::cin >> input;
		return input;
	}
	virtual void WordGuessed() override {
		std::cout << "Word Guessed !!!" << std::endl;
	}

	virtual void GameOver() override {
		std::cout << "!!! Game Over !!!" << std::endl;
		system("pause");
	}

	virtual bool IsGameContinue() override {
		char input;
		while (true) {
			std::cout << "Do you want continue? (y/n): ";
			std::cin >> input;
			switch (input)
			{
			case 'y':
			case 'Y':
				return true;
				break;
			case 'n':
			case 'N':
				return false;
				break;
			default:
				system("cls");
				break;
			}
		}
	}
};

