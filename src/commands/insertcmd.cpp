/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/commandfactory.h"
#include "../../include/commands/insertcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
using namespace std;

InsertCommand::InsertCommand()
{}

int InsertCommand::execute(TextList& text, const SString& cmd)
{
    size_t line = CommandFactory::getLineFromCommand(text, cmd);
    if (line == -1) return -1;

    std::string raw;
    std::cin >> raw;

    std::string formatted;
    formatted = (raw.length() > 80) ? raw.substr(0, 80) : raw;

    SString ret_str(formatted.c_str());

    text.insertLine(ret_str, line);
    return 0;
}
