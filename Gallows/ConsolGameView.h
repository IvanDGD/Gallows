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
		system("cls");
	}

	virtual bool IsGameContinue() override {
		char input;
		while (true) {
			system("cls");
			std::cout << "Do you want continue? (y/n): ";
			std::cin >> input;
			switch (input)
			{
			case 'y':
			case 'Y':
				system("cls");
				return true;
				break;
			case 'n':
			case 'N':
				system("cls");
				return false;
				break;
			default:
				system("cls");
				break;
			}
		}
	}

	void HumanOutput(int mistakes) {
		switch (mistakes)
		{
		case 0:
			std::cout << "__________" << std::endl;
			for (int i = 0; i < 6; i++) {
				if (i == 0) {
					std::cout << " |     | " << std::endl;
				}
				else {
					std::cout << " |       " << std::endl;
				}
			}
			std::cout << "------" << std::endl;
			break;
		case 1:
			std::cout << "__________" << std::endl;
			for (int i = 0; i < 6; i++) {
				if (i == 0) {
					std::cout << " |     | " << std::endl;
				}
				else if (i == 1) {
					
					std::cout << " |     O " << std::endl;
				}
				else {
					std::cout << " |      " << std::endl;
				}
			}
			std::cout << "------" << std::endl;
			break;
		case 2:
			std::cout << "__________" << std::endl;
			for (int i = 0; i < 6; i++) {
				if (i == 0) {
					std::cout << " |     | " << std::endl;
				}
				else if (i == 1) {

					std::cout << " |     O " << std::endl;
				}
				else if (i == 2) {

					std::cout << " |     # " << std::endl;
				}
				else {
					std::cout << " |      " << std::endl;
				}
			}
			std::cout << "------" << std::endl;
			break;
		case 3:
			std::cout << "__________" << std::endl;
			for (int i = 0; i < 6; i++) {
				if (i == 0) {
					std::cout << " |     | " << std::endl;
				}
				else if (i == 1) {

					std::cout << " |   \\ O " << std::endl;
				}
				else if (i == 2) {

					std::cout << " |     # " << std::endl;
				}
				else {
					std::cout << " |      " << std::endl;
				}
			}
			std::cout << "------" << std::endl;
			break;
		case 4:
			std::cout << "__________" << std::endl;
			for (int i = 0; i < 6; i++) {
				if (i == 0) {
					std::cout << " |     | " << std::endl;
				}
				else if (i == 1) {

					std::cout << " |   \\ O / " << std::endl;
				}
				else if (i == 2) {

					std::cout << " |     # " << std::endl;
				}
				else {
					std::cout << " |      " << std::endl;
				}
			}
			std::cout << "------" << std::endl;
			break;
		case 5:
			std::cout << "__________" << std::endl;
			for (int i = 0; i < 6; i++) {
				if (i == 0) {
					std::cout << " |     | " << std::endl;
				}
				else if (i == 1) {

					std::cout << " |   \\ O / " << std::endl;
				}
				else if (i == 2) {

					std::cout << " |     # " << std::endl;
				}
				else if (i == 3) {

					std::cout << " |    / " << std::endl;
				}
				else {
					std::cout << " |      " << std::endl;
				}
			}
			std::cout << "------" << std::endl;
			break;
		case 6:
			std::cout << "__________" << std::endl;
			for (int i = 0; i < 6; i++) {
				if (i == 0) {
					std::cout << " |     | " << std::endl;
				}
				else if (i == 1) {

					std::cout << " |   \\ O / " << std::endl;
				}
				else if (i == 2) {

					std::cout << " |     # " << std::endl;
				}
				else if (i == 3) {

					std::cout << " |    / \\ " << std::endl;
				}
				else {
					std::cout << " |      " << std::endl;
				}
			}
			std::cout << "------" << std::endl;
			break;
		default:
			break;
		}
	}
};

