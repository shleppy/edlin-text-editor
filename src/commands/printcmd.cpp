/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/commandfactory.h"
#include "../../include/commands/printcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

PrintCommand::PrintCommand()
{}

int PrintCommand::execute(TextList& text, const SString& cmd)
{
    if (cmd.getLength() > 1)
    {
        // get number after first char (e.g.: with p352 we would need 352)
        size_t line = CommandFactory::getLineNumberFromCommand(text, cmd);
        text.printLine(line);
    }
    else
    {
        // print whole text file
        text.printAll();
    }
    return 0;
}
