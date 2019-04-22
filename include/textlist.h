/* author: Shelby Hendrickx */
#pragma once
#include <cstring>
#include "sstring.h"
#include "linenode.h"

#define NULLFILE "NULL_FILE"

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
    void printToOut();
    void printToFile(std::string file);

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
    void printAll(std::string file = NULLFILE);

    /**
     * Print a single line
     */
    void printLine(const size_t line);

    /**
     * Computes the number of lines
     */ 
    size_t numberOfLines();

    /**
     * Inserts parameter s at line n pushing back previously existing lines
     */ 
    void insertLine(const SString& str, const size_t line);

    /**
     * Deletes line at parameter line
     */
    void deleteLine(const size_t line);

    /**
     * Extends 
     */ 
    void extendLine(const SString& str, const size_t line);

    /**
     * Checks if list is empty
     */
    bool isEmpty();

};
