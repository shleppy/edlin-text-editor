/* author: Shelby Hendrickx */
#include <iomanip>
#include "../../include/commands/deletecmd.h"
#include "../../include/textutils.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
using namespace std;

DeleteCommand::DeleteCommand()
    :deletedText{nullptr}
{}

int DeleteCommand::execute(TextList& text, const SString& cmd)
{
    size_t lineNr = TextUtils::getLineNumberFromCommand(text, cmd);
    if (lineNr == -1) return - 1;

    deletedText = text.deleteLine(lineNr);
    line = lineNr;

    return 0;
}

void DeleteCommand::undo(TextList& text)
{
    text.insertLine(deletedText, line);
}

void DeleteCommand::redo(TextList& text)
{
    text.deleteLine(line);
}