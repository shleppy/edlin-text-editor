/* author: Shelby Hendrickx */
#include <iostream>
#include <string.h>
#include "../include/sstring.h"
using namespace std;

SString::SString(char* str)
    :str{str}, len{strlen(str)}
{ }

int SString::getLength()
{
    return len;
}

void SString::print()
{
    cout << str;
}

