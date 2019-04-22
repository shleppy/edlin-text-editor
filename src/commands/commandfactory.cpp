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
#include "../../include/commands/quitcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

void CommandFactory::executeCommand(TextList *text, const SString& line) 
{
    Command* cmd;
    switch (line.getData()[0])
    {
        case 'a': cmd = new AppendCommand(); break;
        case 'p': cmd = new PrintCommand(); break;
        case 'i': cmd = new InsertCommand(); break;
        case 'd': cmd = new DeleteCommand(); break;
        case 'x': cmd = new ExtendCommand(); break;
        case 'l': cmd = new LoadCommand(); break;
        case 's': cmd = new SaveCommand(); break;
        case 'h': cmd = new HelpCommand(); break;
        case 'q': cmd = new QuitCommand(); break;
        default: cmd = new HelpCommand(); break;
    }
    cmd->execute(*text, line);
};
