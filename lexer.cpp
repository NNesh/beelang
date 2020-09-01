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

std::string& Lexer::getToken() const
{
    if (entryFile == nullptr || !entryFile->is_open())
    {
        throw std::logic_error("Lexer has no opened files");
    }

    std::string* word = new std::string(); 

    return *word;
}