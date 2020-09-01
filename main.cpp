#include <string>
#include <iostream>
#include <memory>
#include "lexer.h"
#include "syntax.h"


int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cerr << "No passed a name of file" << std::endl;
        return 0;
    }

    try
    {
        auto lexer = std::make_shared<Lexer>(argv[1]);
        Syntax syntax(lexer);

        syntax.makeTree();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    

    return 0;
}
