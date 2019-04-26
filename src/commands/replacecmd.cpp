/* author: Shelby Hendrickx */
#include <iostream>
#include "../../include/commands/replacecmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
#include "../../include/textutils.h"

ReplaceCommand::ReplaceCommand()
{}

int ReplaceCommand::execute(TextList& text, const SString& cmd)
{
    size_t line = TextUtils::getLineNumberFromCommand(text, cmd);
    if (line == -1) return -1;

    SString replText = TextUtils::getLineFromCin();

    text.replaceLine(replText, line);
    return 0;
}

void ReplaceCommand::undo(TextList& text)
{
    // TODO
}

void ReplaceCommand::redo(TextList& text)
{
    // TODO
}
