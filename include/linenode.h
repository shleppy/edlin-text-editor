/* author: Shelby Hendrickx */
#pragma once
#include "sstring.h"

/**
 * Simple singly linked list node containing a string line
 */
class LineNode
{
private:
    LineNode *next;
    SString data;
public:
    LineNode(const SString& data);

    /**
     * Returns next node
     */
    LineNode* getNext() const;

    /**
     * Get data
     */
    SString getData() const;

    /**
     * Sets node as next
     */
    void appendNextNode(LineNode *node);

    /**
     * Prints data
     */
    void printLine() const;
};
