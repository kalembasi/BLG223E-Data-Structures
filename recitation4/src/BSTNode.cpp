#include <stdlib.h>
#include "BSTNode.h"

Node::Node(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

void Node::set_data(int data)
{
    this->data = data;
}

int Node::get_data()
{
    return this->data;
}

void Node::set_left(Node* node)
{
    this->left = node;
}

Node* Node::get_left()
{
    return this->left;
}

void Node::set_right(Node* node)
{
    this->right = node;
}

Node* Node::get_right()
{
    return this->right;
}