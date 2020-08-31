#pragma once

#include <fstream>
#include <string>

class Lexer
{
public:
    Lexer(const std::string *path);
    Lexer(const char* path);
    ~Lexer();

    std::string& getToken() const;

private:
    std::ifstream* entryFile;

    std::ifstream* openFile(const char* path);
    void closeFile();

    char getNext();
};