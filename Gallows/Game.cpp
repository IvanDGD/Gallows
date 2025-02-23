#include "Game.h"
#include "Login.h"
#include "MainMenu.h"


Game::Game(std::shared_ptr<WordsManager> manager, std::unique_ptr<IGameView> view)
    : wordsBuilder(manager), view(std::move(view)), mistakes(0), mark(0) {}

Game::~Game() {}

void Game::Start(Login& loginName)
{
    do {
        system("cls");
        try {
            current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
        }
        catch (const std::runtime_error& e) {
            std::cout << "No more words left! Game Win!!!\n";
            loginName.Save();
            startMenu->StartMenu();
            break;
        }

        view->DisplayWord(current_word->GetExternalWord());
        view->DisplayMistakes(mistakes);
        view->HumanOutput(mistakes);

        while (!current_word->isGuessed() && mistakes < MAX_MISTAKES) {
            char letter = view->GetInputLetter();
            system("cls");
            if (!current_word->InputLetter(letter))
                ++mistakes;

            view->DisplayWord(current_word->GetExternalWord());
            view->DisplayMistakes(mistakes);
            view->HumanOutput(mistakes);
        }

        if (mistakes < MAX_MISTAKES) {
            view->WordGuessed();
            loginName.IncrementMark();
        }
        else {
            view->GameOver();
            loginName.Save();
            startMenu->StartMenu();
            break;
        }
    } while (view->IsGameContinue());
}
