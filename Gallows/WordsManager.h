#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "Cryptographer.h"

using std::vector;
using std::fstream;
using std::string;
using std::ios;

class WordsManager
{
private:
    vector<string> words;
    Cryptographer crypto;
    const int encryptionKey = 3;

public:
    WordsManager() {
        Load();
    }

    void Save()
    {
        fstream output("Words.txt", ios::out);

        for (const auto& word : words)
        {
            string encrypted = crypto.Encrypt(word, encryptionKey);
            output << encrypted << "\n";
        }
        output.close();

    }

    void Load()
    {
        words.clear();
        fstream input("Words.txt", ios::in);

        string encryptedWord;
        while (std::getline(input, encryptedWord))
        {
            if (!encryptedWord.empty()) {
                string decryptedWord = crypto.Decrypt(encryptedWord, encryptionKey);
                words.push_back(decryptedWord);
            }
        }
        input.close();
    }

    const vector<string>& GetWords() const
    {
        return words;
    }

    void Append(const string& word)
    {
        string encrypted = crypto.Encrypt(word, encryptionKey);
        words.push_back(word);
        fstream output("Words.txt", ios::app);
        output << encrypted << "\n";
        output.close();
    }
};