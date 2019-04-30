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
    :insertionText{""}
{}

int InsertCommand::execute(TextList& text, const SString& cmd)
{
    size_t lineNr = TextUtils::getLineNumberFromCommand(text, cmd);
    if (lineNr == -1) return -1;

    line = lineNr;
    insertionText = TextUtils::getLineFromCin().get()->getData();

    text.insertLine(insertionText, lineNr - 1);
    return 0;
}

void InsertCommand::undo(TextList& text)
{
    // TODO
    text.deleteLine(line);
}

void InsertCommand::redo(TextList& text)
{
    // TODO
    text.insertLine(insertionText, line - 1);
}

