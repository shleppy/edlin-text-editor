/* author: Shelby Hendrickx */
#include <iostream>
#include "../include/linenode.h"
using namespace std;

LineNode::LineNode(SString str)
    :data{str}, next{nullptr}
{ }

LineNode* LineNode::getNext()
{
    return next;
}

void LineNode::setData(SString str)
{
    data = str;
}

SString LineNode::getData()
{
    return data;
}

void LineNode::appendNextNode(LineNode *node)
{
    next = node;
}

void LineNode::printLine()
{
    data.print();
    cout << "\n";
}

