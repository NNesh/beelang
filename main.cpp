#include <string>
#include <iostream>
#include "lexer.h"


int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cerr << "No passed a name of file" << std::endl;
        return 0;
    }

    try
    {
        Lexer lexer(argv[1]);

        auto token = lexer.getToken();

        std::cout << token << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    

    return 0;
}
