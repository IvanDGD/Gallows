#include "GameWordsBuilder.h"


GameWordsBuilder::GameWordsBuilder(const shared_ptr<WordsManager>& manager)
	:manager(manager)
{
	buffer = manager->GetWords();
}

GameWord GameWordsBuilder::GetRandomWord()
{
    int rand_value = rand() % buffer.size();
    auto&& first = buffer[rand_value];
    GameWord result(first);
    buffer.erase(buffer.begin() + rand_value);
    return result;
}
