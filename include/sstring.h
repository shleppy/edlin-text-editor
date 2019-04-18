/* author: Shelby Hendrickx */
#ifndef SSTRING_H
#define SSTRING_H

/**
 * simple string representation of char[] with length variable
 */
class SString
{
    private:
        int len;
        char *str;
    public:
        SString(char* str);
        SString(const SString &other);
        ~SString();
        void print();
        int getLength();
};

#endif // SSTRING_H