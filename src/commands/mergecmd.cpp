/* author: Shelby Hendrickx */
#include <iomanip>
#include "../../include/commands/mergecmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
#include "../../include/textutils.h"

MergeCommand::MergeCommand()
{}

int MergeCommand::execute(TextList& text, const SString& cmd)
{
    size_t line = TextUtils::getLineNumberFromCommand(text, cmd);
    text.mergeLine(line);
    return 0;
}
