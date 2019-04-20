/* author: Shelby Hendrickx */
#ifndef SSTRING_H
#define SSTRING_H
#include <cstring>

/**
 * simple string representation of char[] with length variable
 */
class SString
{
private:
    size_t len;
    char *str;
public:
    /**
     * Constructor with content
     */
    SString(const char *str);

    /**
     * Copy constructor
     */ 
    SString(const SString& other);

    /**
     * Move constructor
     */ 
    //SString(SString&& other);

    /**
     * Destructor
     */
    virtual ~SString();

    /**
     * Returns content of string
     */
    const char* getData() const;

    /**
     * Print content
     */
    void print() const;

    /**
     * Get Length of content
     */
    size_t getLength() const;

    /**
     * Plus operator for concatenating strings
     */
    SString operator+(const SString& str) const;
};

#endif // SSTRING_H