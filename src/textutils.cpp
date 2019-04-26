/* author: Shelby Hendrickx */
#include <iostream>
#include <cstring>
#include <../include/textutils.h>

size_t TextUtils::getLineNumberFromCommand(TextList& text, const SString& line)
{
    size_t line_nr = atol(line.getData() + 1);
    
    // if no line is passed, work on last line
    if (line_nr = 0) return text.numberOfLines();

    // if line number is more than available lines print error and return -1
    if (line_nr > text.numberOfLines())
    {
        std::cerr << "Invalid line" << std::endl;
        return -1;
    }

    // in all other cases return converted line
    return line_nr;
};

SString* TextUtils::getLineFromCin()
{
    std::string raw;
    getline(std::cin, raw);

    std::string formatted;
    formatted = (raw.length() > 80) ? raw.substr(0, 80) : raw;

    SString *ret_str = new SString(formatted.c_str());
    return ret_str;
}