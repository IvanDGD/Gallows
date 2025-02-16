#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

class Cryptographer
{
private:
    char ShiftChar(char ch, int shift) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            return static_cast<char>(base + (ch - base + shift + 26) % 26);
        }
        return ch;
    }

public:
    string Encrypt(const string& str, int shift) {
        string encrypted = str;
        for (char& ch : encrypted) {
            ch = ShiftChar(ch, shift);
        }
        return encrypted;
    }

    string Decrypt(const string& str, int shift) {
        return Encrypt(str, -shift);
    }

    vector<string> Encrypt(const vector<string>& strList, int shift) {
        vector<string> encryptedList;
        encryptedList.reserve(strList.size());
        for (const auto& str : strList) {
            encryptedList.push_back(Encrypt(str, shift));
        }
        return encryptedList;
    }
};
