#include <iostream>
#include "syntax.h"

Syntax::Syntax(const std::shared_ptr<Lexer>& lexer)
{
    this->lexer = lexer;
}

void Syntax::makeTree()
{
    auto token = lexer->getToken();

    while (!token->empty())
    {
        std::cout << "Word: " << token->toString() << std::endl;

        token = lexer->getToken();
    }
}