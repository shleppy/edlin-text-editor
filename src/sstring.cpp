/* author: Shelby Hendrickx */
#include <iostream>
#include <cstring>
#include "../include/sstring.h"
using namespace std;

SString::SString(const char* str)
    :len{strlen(str)}, str{new char[len + 1]}
{
    strcpy(this->str, str);
}

SString::SString(const SString& str) 
    :len{str.len}, str{new char[len + 1]}
{ 
    strcpy(this->str, str.str);
}

SString::~SString()
{
    delete[] str;
}

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
    cout << str;
}

SString SString::operator+(const SString& str) const
{
    char* cat = new char[len + str.len + 1];
    strcpy(cat, this->str);
    strcpy(&cat[len], str.str);

    SString result(cat);

    delete[] cat;
    return result;
}