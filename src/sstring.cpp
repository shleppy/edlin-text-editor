/* author: Shelby Hendrickx */
#include <iostream>
#include <string.h>
#include "../include/sstring.h"
using namespace std;

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

void SString::print() const
{
    cout << str;
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