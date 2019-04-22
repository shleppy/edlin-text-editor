/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/appendcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
using namespace std;

AppendCommand::AppendCommand()
{}

int AppendCommand::execute(TextList& text, const SString& str)
{
    std::string raw;
    std::cin >> raw;

    std::string formatted;
    formatted = (raw.length() > 80) ? raw.substr(0, 80) : raw;

    SString ret_str(formatted.c_str());
    text.appendLine(ret_str);

    return 0;
}
