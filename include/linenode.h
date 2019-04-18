/* author: Shelby Hendrickx */
#ifndef LINENODE_H
#define LINENODE_H
#include "sstring.h"

/**
 * Simple Singly Linked List
 */
class LineNode
{
    private:
        LineNode *next;
        SString data;
    public:
        LineNode(SString data);

        /**
         * Returns next node
         */ 
        LineNode* getNext();

        /**
         * Set data
         */ 
        void setData(SString data);

        /**
         * Get data
         */ 
        SString getData();

        /**
         * Sets node as next
         */ 
        void appendNextNode(LineNode *node);

        /**
         * Prints data
         */ 
        void printLine();
};

#endif // LINENODE_H