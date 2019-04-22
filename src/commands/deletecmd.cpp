/* author: Shelby Hendrickx */
#include <iomanip>
#include "../../include/commands/commandfactory.h"
#include "../../include/commands/deletecmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
using namespace std;

DeleteCommand::DeleteCommand()
{}

int DeleteCommand::execute(TextList& text, const SString& cmd)
{
    size_t line = CommandFactory::getLineFromCommand(text, cmd);
    if (line == -1) return - 1;

    text.deleteLine(line);
    return 0;
}
