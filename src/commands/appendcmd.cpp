/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/appendcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
#include "../../include/textutils.h"
using namespace std;

AppendCommand::AppendCommand()
    :insertionText{""}
{ }

int AppendCommand::execute(TextList& text, const SString& str)
{
    SString appText = TextUtils::getLineFromCin().get()->getData();
    text.appendLine(appText);
    insertionText = appText;
    line = text.numberOfLines();
    return 0;
}

void AppendCommand::undo(TextList& text)
{
    text.deleteLine(line);
}

void AppendCommand::redo(TextList& text)
{
    text.appendLine(insertionText);
}