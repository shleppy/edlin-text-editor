/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/insertcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
#include "../../include/textutils.h"
using namespace std;

InsertCommand::InsertCommand()
{}

int InsertCommand::execute(TextList& text, const SString& cmd)
{
    size_t line = TextUtils::getLineNumberFromCommand(text, cmd);
    if (line == -1) return -1;

    SString insText = TextUtils::getLineFromCin();

    text.insertLine(insText, line);
    return 0;
}

void InsertCommand::undo(TextList& text)
{
    // TODO
}

void InsertCommand::redo(TextList& text)
{
    // TODO
}

