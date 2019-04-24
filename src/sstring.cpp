/* author: Shelby Hendrickx */
#include <iostream>
#include <cstring>
#include <string>
#include "../include/sstring.h"

SString::SString(const char* str)
    :len{strlen(str)}, str{new char[len + 1]}
{
    strcpy(this->str, str);
}

SString::SString(const SString& str) 
    :len(str.len), str(new char[str.len + 1])
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

void SString::subStr(size_t start, size_t end)
{
    std::string orig(str);
    const char* sub = orig.substr(start, end - 1).c_str();
    delete[] str;
    len = strlen(sub);
    str = new char[len + 1];
    strcpy(str, sub);
}