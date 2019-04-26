/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/printcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
#include "../../include/textutils.h"

PrintCommand::PrintCommand()
{}

int PrintCommand::execute(TextList& text, const SString& cmd)
{
    if (cmd.getLength() > 1)
    {
        // print single line
        size_t line = TextUtils::getLineNumberFromCommand(text, cmd);
        text.printLine(line);
    }
    else
    {
        // print all text
        text.printAll();
    }
    return 0;
}
