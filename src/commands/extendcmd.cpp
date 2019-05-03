/* author: Shelby Hendrickx */
#include <iostream>
#include "../../include/commands/extendcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
#include "../../include/textutils.h"

ExtendCommand::ExtendCommand()
    :original{""}, extended{""} 
{}

int ExtendCommand::execute(TextList& text, const SString& cmd)
{
    size_t lineNr = TextUtils::getLineNumberFromCommand(text, cmd);
    if (lineNr == -1) return -1;

    line = lineNr;
    original = text.getLine(line);
    std::cout << " oops " << std::endl;
    SString extText = TextUtils::getLineFromCin().get()->getData();
    extended = extText;
    text.extendLine(extText, lineNr);
    return 0;
}

void ExtendCommand::undo(TextList& text)
{
    text.replaceLine(original, line);
}

void ExtendCommand::redo(TextList& text)
{
    text.extendLine(extended, line);
}

