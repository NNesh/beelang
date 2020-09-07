#include "node.h"

Node::Node(Token* token)
{
    this->token = std::shared_ptr<Token>(token);
}

Node::Node(Node* parent, Token* token)
{
    this->token = std::shared_ptr<Token>(token);
    this->parent = std::shared_ptr<Node>(parent);
}

Node::Node(const std::shared_ptr<Token>& token)
{
    this->token = token;
}

Node::Node(const std::shared_ptr<Node>& parent, const std::shared_ptr<Token>& token)
{
    this->token = token;
    this->parent = parent;
}

Node& Node::addChild(Node* node)
{
    childs.push_back(std::unique_ptr<Node>(node));
}

std::shared_ptr<Token> Node::getIdToken(const std::string& name)
{
    if (idTable.count(name) == 0 && parent.use_count() > 0) {
        parent->getIdToken(name);
    }

    return idTable[name];
}
