/* author: Shelby Hendrickx */
#ifndef TEXTLIST_H
#define TEXTLIST_H
#include "sstring.h"
#include "linenode.h"

/**
 * Container for the full text file
 */ 
class TextList
{
    private:
        LineNode *header;
        LineNode *footer;
        LineNode *runner;
        int numOfLines;

        void setRunner();

    public:
        /**
         * Default constructor
         */ 
        TextList();

        /**
         * Destructor
         */
        ~TextList();

        /**
         * Appends parameter s as a new line to the text file.
         */ 
        void appendLine(SString s);

        /**
         * Prints all lines
         */ 
        void printAll();

        /**
         * Returns number of lines in the text file
         */ 
        int numberOfLines();

        /**
         * Inserts parameter s at line n pushing back previously existing lines
         */ 
        void insertLine(SString s, int n);
};

#endif // TEXTLIST_H