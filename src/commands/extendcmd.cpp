/* author: Shelby Hendrickx */
#include <iostream>
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

    SString extText = TextUtils::getLineFromCin().get()->getData();

    text.extendLine(extText, line);
    return 0;
}

void ExtendCommand::undo(TextList& text)
{
    // TODO
}

void ExtendCommand::redo(TextList& text)
{
    // TODO
}


