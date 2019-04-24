/* author: Shelby Hendrickx */
#include <iostream>
#include "../../include/commands/commandfactory.h"
#include "../../include/commands/replacecmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

ReplaceCommand::ReplaceCommand()
{}

int ReplaceCommand::execute(TextList& text, const SString& cmd)
{
    size_t line = CommandFactory::getLineNumberFromCommand(text, cmd);
    if (line == -1) return -1;

    std::string raw;
    std::cin >> raw;

    std::string formatted;
    formatted = (raw.length() > 80) ? raw.substr(0, 80) : raw;

    SString ret_str(formatted.c_str());

    text.replaceLine(ret_str, line);

    return 0;
}
