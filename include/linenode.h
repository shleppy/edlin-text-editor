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
    LineNode(const SString& str);

    /**
     * Returns next node
     */
    LineNode* getNext() const;

    /**
     * Sets node as next
     */ 
    void appendNextNode(LineNode *node);
    
    /**
     * Get data
     */
    const SString& getData() const;

    /**
     * Sets node as next
     */
    void appendNextNode(LineNode *node);

    /**
     * Set data
     */
    void setData(const SString& str);

    /**
     * Prints data
     */
    void printLine() const;
};
