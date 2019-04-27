/* author: Shelby Hendrickx */
#pragma once
#include <memory>
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
    std::shared_ptr<SString> deleteLine(const size_t line);

    /**
     * Truncates line starting from given position
     */
    void truncateLine(const size_t line, const size_t position);

    /**
     * Appends str to the given line
     */ 
    void extendLine(const SString& str, const size_t line);

    /**
     * Replaces given line completely with str
     */
    void replaceLine(const SString& str, const size_t line);

    /**
     * Merges two consecutive line
     */
    void mergeLine(const size_t line);

    /**
     * Splits the given line starting at given word
     */
    void splitLine(const SString& fromWord, const size_t line);

    /**
     * Checks if list is empty
     */
    bool isEmpty();

};
