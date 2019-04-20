/* author: Shelby Hendrickx */
#include "../../include/commands/commandfactory.h"
#include "../../include/commands/command.h"
#include "../../include/commands/appendcmd.h"
#include "../../include/commands/printcmd.h"
#include "../../include/commands/insertcmd.h"
#include "../../include/commands/deletecmd.h"
#include "../../include/commands/extendcmd.h"
#include "../../include/commands/loadcmd.h"
#include "../../include/commands/savecmd.h"
#include "../../include/commands/helpcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

Command* CommandFactory::getCommand(TextList const& text, const SString& str) {
    Command *cmd;
    switch (str.getData()[0]) 
    {
        case 'a': cmd = new AppendCommand();
        case 'p': cmd = new PrintCommand();
        case 'i': cmd = new InsertCommand();
        case 'd': cmd = new DeleteCommand();
        case 'x': cmd = new ExtendCommand();
        case 'l': cmd = new LoadCommand();
        case 's': cmd = new SaveCommand();
        case 'h': cmd = new HelpCommand();
        default: return nullptr;
    }
    return cmd;
}


