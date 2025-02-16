#pragma once
#include "WordsManager.h"
#include "GameWord.h"

using std::shared_ptr;

class GameWordsBuilder
{
private:
	vector<string> buffer;
	shared_ptr<WordsManager> manager;
public:
	GameWordsBuilder(const shared_ptr<WordsManager>& manager)
		:manager(manager)
	{
		buffer = manager->GetWords();
	}

	GameWord GetRandomWord()  
	{
		int rand_value = rand() % buffer.size();
		auto&& first = buffer[rand_value];
		GameWord result(first);

		buffer.erase(buffer.begin() + rand_value);
		return result;
	}
};

