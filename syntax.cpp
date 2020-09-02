#include <iostream>
#include "syntax.h"

Syntax::Syntax(const std::shared_ptr<Lexer>& lexer)
{
    this->lexer = lexer;
}

void Syntax::makeTree()
{
    auto token = lexer->getToken();

    if (token->getType() != Token::Type::PACKAGE)
        throw std::logic_error("Error: the script file doesn't has a package keyword in begin");
    
    token = lexer->getToken();

    if (token->getType() != Token::Type::ID)
        throw std::logic_error("Error: no package name");

    // TODO: create a node

    while (!token->empty())
    {
        std::cout << "Token: " << token->toString() << std::endl;

        token = lexer->getToken();
    }
}