#pragma once

#include "map"

#define ATTR_KEY_TYPE const char*
#define ATTR_VALUE_TYPE const char *

class Token
{
private:
    std::map<ATTR_KEY_TYPE, ATTR_VALUE_TYPE> attrs;

public:
    enum Type {
        NONE = 0,
        INT,
        IF,
        PLUS,
        MINUS,
        EQUAL,
        ASSIGN,
        PACKAGE,
        ID
    };

    Type type;
    
    Token(Token::Type type);
    virtual ~Token() = default;

    virtual Token& addAttribute(ATTR_KEY_TYPE key, ATTR_VALUE_TYPE value);

    Type getType() const;
    bool empty() const;

    operator const char*()
    {
        if (type == Type::IF)
            return "<IF>";
        if (type == Type::EQUAL)
            return "<EQUAL>";
        if (type == Type::PLUS)
            return "<+>";
        if (type == Type::ID)
            return "<ID>";
        
        return "<None>";
    }
};