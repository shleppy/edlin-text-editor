/* author: Shelby Hendrickx */
#include <iomanip>
#include "../../include/commands/deletecmd.h"
#include "../../include/textutils.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
#include <iostream>
using namespace std;

DeleteCommand::DeleteCommand()
    :deletedText{""}
{}

int DeleteCommand::execute(TextList& text, const SString& cmd)
{
    size_t lineNr = TextUtils::getLineNumberFromCommand(text, cmd);
    if (lineNr == -1) return - 1;

    std::shared_ptr<SString> delPtr = text.deleteLine(lineNr);
    deletedText = delPtr.get()->getData();
    line = lineNr;

    return 0;
}

void DeleteCommand::undo(TextList& text)
{
    text.insertLine(deletedText, line - 1);
}

void DeleteCommand::redo(TextList& text)
{
    text.deleteLine(line);
}