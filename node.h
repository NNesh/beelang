#pragma once

#include <vector>
#include <map>
#include "token.h"

class Node
{
public:
    Node(Token* token);
    Node(const std::shared_ptr<Token>& token);
    Node(Node* parent, Token* token);
    Node(const std::shared_ptr<Node>& parent, const std::shared_ptr<Token>& token);

    Node& addChild(Node* child);

    std::shared_ptr<Token> getIdToken(const std::string& name);

private:
    std::shared_ptr<Token> token;

    std::vector<std::unique_ptr<Node>> childs;
    std::shared_ptr<Node> parent;

    // Table of IDs
    std::map<std::string, std::shared_ptr<Token>> idTable;
};
