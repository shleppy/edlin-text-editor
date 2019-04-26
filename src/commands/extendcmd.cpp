/* author: Shelby Hendrickx */
#include <iostream>
#include "../../include/commands/commandfactory.h"
#include "../../include/commands/extendcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
#include "../../include/textutils.h"

ExtendCommand::ExtendCommand()
{}

int ExtendCommand::execute(TextList& text, const SString& cmd)
{
    size_t line = TextUtils::getLineNumberFromCommand(text, cmd);
    if (line == -1) return -1;

    SString extText = TextUtils::getLineFromCin();

    text.extendLine(extText, line);
    return 0;
}
