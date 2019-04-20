/* author: Shelby Hendrickx */
#include <iostream>
#include <string.h>
#include "../include/sstring.h"

SString::SString(const char* str)
    :str{str}, len{strlen(str)}
{ }

SString::SString(const SString& str)
    :str{str.str}, len{str.len}
{ }

SString::~SString() {}

size_t SString::getLength() const
{
    return len;
}

const char* SString::getData() const
{
    return str;
}

void SString::print() const
{
    std::cout << str;
}

SString SString::operator+(const SString& str) const
{
    char* cat = new char[len + str.len + 1];
    strcpy(cat, this->str);
    strcpy(&cat[this->len], str.str);
    SString result(cat);
    delete[] cat;
    return result;
}
