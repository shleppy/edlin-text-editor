/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/appendcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

AppendCommand::AppendCommand()
{}

int AppendCommand::execute(TextList& text, const SString& str)
{
    std::string line;
    bool isInvalid = true;
    while (isInvalid)
    {
        std::cin >> line;
        if (line.length() <= 80) isInvalid = false;
    }

    SString ret(line.c_str());
    text.appendLine(ret);
    return 0;
}
