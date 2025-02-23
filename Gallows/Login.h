#pragma once 
#include "Cryptographer.h"
#include <iostream>
#include <fstream>
#include <map>

class Login {
private:
    std::string name;
    int mark;
    int shift = 3;
public:
    Login() : name(""), mark(0) {}

    void Save() {
        std::map<std::string, int> records;
        Cryptographer cryptographer;

        std::ifstream fileIn("Records.txt");
        if (fileIn.is_open()) {
            std::string encryptedName, encryptedMark;
            while (std::getline(fileIn, encryptedName) && std::getline(fileIn, encryptedMark)) {
                std::string decryptedName = cryptographer.Decrypt(encryptedName, shift);
                int decryptedMark = std::stoi(cryptographer.Decrypt(encryptedMark, shift));
                records.insert(std::make_pair(decryptedName, decryptedMark));
            }
            fileIn.close();
        }

        auto it = records.find(name);
        if (it == records.end() || mark > it->second) {
            records[name] = mark;
        }

        std::ofstream fileOut("Records.txt", std::ios::out);
        if (fileOut.is_open()) {
            for (auto it = records.begin(); it != records.end(); it++) {
                fileOut << cryptographer.Encrypt(it->first, shift) << "\n";
                fileOut << cryptographer.Encrypt(std::to_string(it->second), shift) << "\n";
            }
            fileOut.close();
        }
    }

    void Load() {
        Cryptographer cryptographer;
        std::ifstream file("Records.txt");
        if (file.is_open()) {
            std::string encryptedName, encryptedMark;
            while (std::getline(file, encryptedName) && std::getline(file, encryptedMark)) {
                std::string decryptedName = cryptographer.Decrypt(encryptedName, shift);
                int decryptedMark = std::stoi(cryptographer.Decrypt(encryptedMark, shift));
                if (decryptedName == name) {
                    mark = decryptedMark;
                    break;
                }
            }
            file.close();
        }
    }

    std::map<std::string, int> LoadAllRecords() {
        std::ifstream file("Records.txt", std::ios::in);
        std::map<std::string, int> records;

        if (file.is_open()) {
            Cryptographer cryptographer;
            std::string encryptedName, encryptedMark;

            while (std::getline(file, encryptedName) && std::getline(file, encryptedMark)) {
                std::string decryptedName = cryptographer.Decrypt(encryptedName, shift);
                int decryptedMark = std::stoi(cryptographer.Decrypt(encryptedMark, shift));
                records[decryptedName] = decryptedMark;
            }
            file.close();
        }

        return records;
    }

    void SetName(const std::string& newName) { name = newName; }
    std::string GetName() const { return name; }
    int GetMark() const { return mark; }
    void IncrementMark() { ++mark; }
};
