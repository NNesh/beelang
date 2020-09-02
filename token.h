#pragma once

#include "map"
#include <memory>

#define ATTR_KEY_TYPE const char*
#define ATTR_VALUE_TYPE const char *

class Token
{
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
        ID,
        RETURN,
    };

    Type type;
    
    Token(Token::Type type, const char* val);
    virtual ~Token() = default;

    virtual Token& addAttribute(ATTR_KEY_TYPE key, ATTR_VALUE_TYPE value);

    Type getType() const;
    bool empty() const;

    std::string toString();

private:
    std::map<ATTR_KEY_TYPE, ATTR_VALUE_TYPE> attrs;
    std::string value;

    static std::map<Type, const char*> typeStr;
};