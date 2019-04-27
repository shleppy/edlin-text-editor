/* author: Shelby Hendrickx */
#include <iostream>
#include "../../include/commands/splitcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
#include "../../include/textutils.h"

SplitCommand::SplitCommand()
{}

int SplitCommand::execute(TextList& text, const SString& cmd)
{
    size_t line = TextUtils::getLineNumberFromCommand(text, cmd);
    if (line == -1) return -1;

    SString splitWord = TextUtils::getLineFromCin().get()->getData();

    text.splitLine(splitWord, line);
    return 0;
}

void SplitCommand::undo(TextList& text)
{
    // TODO
}

void SplitCommand::redo(TextList& text)
{
    // TODO
}

