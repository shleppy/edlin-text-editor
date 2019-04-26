/* author: Shelby Hendrickx */
#include <iostream>
#include <cstring>
#include <../include/textutils.h>

size_t TextUtils::getLineNumberFromCommand(TextList& text, const SString& line)
{
    size_t line_nr = atol(line.getData() + 1);
    if (line.getLength() <= 1 || line_nr > text.numberOfLines())
    {
        std::cout << "Invalid line" << std::endl;
        return -1;
    }
    return line_nr;
};

SString TextUtils::getLineFromCin()
{
    std::string raw;
    std::cin >> raw;

    std::string formatted;
    formatted = (raw.length() > 80) ? raw.substr(0, 80) : raw;

    SString ret_str(formatted.c_str());

    return ret_str;
}