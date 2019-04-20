/* author: Shelby Hendrickx */
#ifndef TEXTLIST_H
#define TEXTLIST_H
#include <cstring>
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
    size_t numOfLines = 0;

    void setRunner(size_t i);

public:
    /**
     * Default constructor
     */ 
    TextList();

    /**
     * Destructor
     */
    virtual ~TextList();

    /**
     * Appends parameter s as a new line to the text file.
     */ 
    void appendLine(const SString& str);

    /**
     * Prints all lines
     */ 
    void printAll();

    /**
     * Print a single line
     */
    void printLine(const size_t line);

    /**
     * Returns number of lines in the text file
     */ 
    size_t numberOfLines() const;

    /**
     * Inserts parameter s at line n pushing back previously existing lines
     */ 
    void insertLine(const SString& str, const size_t line);

    /**
     * Deletes line at parameter line
     */
    void deleteLine(const size_t line);
};

#endif // TEXTLIST_H