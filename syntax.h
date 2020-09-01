#pragma once

#include <memory>
#include "lexer.h"

class Syntax
{
public:
    Syntax(const std::shared_ptr<Lexer>& lexer);
    virtual ~Syntax() = default;

    virtual void makeTree();

private:
    std::shared_ptr<Lexer> lexer;
};