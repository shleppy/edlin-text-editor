/* author: Shelby Hendrickx */
#include <iostream>
#include "../include/linenode.h"
using namespace std;

LineNode::LineNode(const SString& str)
    :data{str}, next{nullptr}
{ }

LineNode* LineNode::getNext() const
{
    return next;
}

SString LineNode::getData() const
{
    return data;
}

void LineNode::appendNextNode(LineNode *node)
{
    next = node;
}

void LineNode::printLine() const
{
    data.print();
    cout << "\n";
}

