#include <cstring>
#include "token.h"

std::map<Token::Type, const char*> Token::typeStr = {
    { Token::Type::NONE, "None" },
    { Token::Type::INT, "Integer" },
    { Token::Type::ID, "Id" },
    { Token::Type::PACKAGE, "Package" },
    { Token::Type::PLUS, "+" },
    { Token::Type::MINUS, "-" },
    { Token::Type::ASSIGN, "=" },
    { Token::Type::RETURN, "return" },
    { Token::Type::FUNCTION, "function" },
    { Token::Type::OPEN_CURLY, "{"},
    { Token::Type::CLOSED_CURLY, "}" },
};


Token::Token(Token::Type type, const char* val)
{
    value = val;
    this->type = type;
}

Token& Token::addAttribute(ATTR_KEY_TYPE key, ATTR_VALUE_TYPE value)
{
    attrs[key] = value;
}

Token::Type Token::getType() const
{
    return type;
}

bool Token::empty() const
{
    return type == Token::Type::NONE;
}

std::string Token::toString()
{
    static std::string postfix { ">" };
    static std::string prefix { "<" };
    static std::string splitter { ", " };

    std::string ts { typeStr[type] };
    return prefix + ts + splitter + value + postfix;
}