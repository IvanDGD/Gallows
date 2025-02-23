#pragma once
#include "Game.h"
#include "Login.h"
#include "ConsolGameView.h"
#include "WordsManager.h"
#include <iostream>

class MainMenu {
private:
    WordsManager manager;
    ConsolGameView consoleView;
    Game game;
    Login loginName;
    std::string name;
public:
    

    MainMenu()
        : manager(), consoleView(), game(std::make_shared<WordsManager>(manager), std::make_unique<ConsolGameView>(consoleView)) {}

    void NewGame() {
        std::cout << "Enter login: ";
        std::cin >> name;

        Login login;
        login.SetName(name);
        login.Load();

        game.Start(login);
    }

    void Records() {
        system("cls");

        Login login;
        std::map<std::string, int> records = login.LoadAllRecords();

        if (records.empty()) {
            std::cout << "No records found.\n";
        }
        else {
            std::vector<std::pair<std::string, int>> sortedRecords(records.begin(), records.end());

            std::sort(sortedRecords.begin(), sortedRecords.end(),
                [](const auto& a, const auto& b) { return a.second > b.second; });

            std::cout << "High Scores:\n";
            for (const auto& entry : sortedRecords) {
                std::cout << entry.first << " - " << entry.second << " points\n";
            }
        }

        system("pause");
        system("cls");
    }

    void AddWord() {
        system("cls");
        std::string word;
        std::cout << "Enter word to add: ";
        std::cin >> word;
        manager.Append(word);
        std::cout << "Word added successfully!" << std::endl;
        system("cls");
    }

    void Settings() {
        int choice;
        do {
            std::cout << "Settings Menu:\n";
            std::cout << "1. Add Word\n";
            std::cout << "2. Back to Main Menu\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                system("cls");
                AddWord();
                break;
            default:
                system("cls");
                break;
            }
        } while (choice != 2);
    }

    void StartMenu() {
        int choice;

        do {
            std::cout << "New Game (1)\n";
            std::cout << "Records (2)\n";
            std::cout << "Settings (3)\n";
            std::cout << "Exit (4)\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                system("cls");
                NewGame();
                break;
            case 2:
                system("cls");
                Records();
                break;
            case 3:
                system("cls");
                Settings();
                system("cls");
                break;
            default:
                system("cls");
                break;
            }
        } while (choice != 4);
    }
};
