/* author: Shelby Hendrickx */
#include <iostream>
#include "../include/linenode.h"

LineNode::LineNode(const SString& str)
    :data{str}, next{nullptr}
{ }

LineNode* LineNode::getNext() const
{
    return next;
}

void LineNode::appendNextNode(LineNode *node)
{
    // ERROR HERE
    next = node;
}

SString LineNode::getData() const
{
    return data;
}


void LineNode::printLine() const
{
    data.print();
    std::cout << endl;
}
