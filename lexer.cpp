#include "lexer.h"

Lexer::Lexer(const std::string *path)
{
    openFile(path->c_str());
}

Lexer::Lexer(const char* path)
{
    openFile(path);
}

Lexer::~Lexer()
{
    closeFile();
}

std::ifstream* Lexer::openFile(const char* path)
{
    entryFile = new std::ifstream(path, std::ifstream::in);
}

void Lexer::closeFile()
{
    delete entryFile;
}

char Lexer::getNext()
{
    return entryFile->get();;
}

Token* Lexer::getToken() const
{
    if (entryFile == nullptr || !entryFile->is_open())
    {
        throw std::logic_error("Lexer has no opened files");
    }

    std::string word;
    *entryFile >> word;

    Token::Type type = Token::Type::NONE;

    if (word == "if")
        type = Token::Type::IF;
    else if (word == "=")
        type = Token::Type::ASSIGN;
    else if (word == "+")
        type = Token::Type::PLUS;
    else if (word == "-")
        type = Token::Type::MINUS;
    else if (word == "==")
        type = Token::Type::EQUAL;
    else if (word == "package")
        type = Token::Type::PACKAGE;
    else if (word == "return")
        type = Token::Type::RETURN;
    else if (!word.empty())
        type = Token::Type::ID;

    return new Token(type, word.c_str());
}