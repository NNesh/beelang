#include "token.h"
#include <cstring>

Token::Token(Token::Type type)
{
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