#pragma once

#include <fstream>
#include <string>
#include "token.h"

class Lexer
{
public:
    Lexer(const std::string *path);
    Lexer(const char* path);
    virtual ~Lexer();

    Token* getToken() const;

private:
    std::ifstream* entryFile;

    std::ifstream* openFile(const char* path);
    void closeFile();

    char getNext();
};