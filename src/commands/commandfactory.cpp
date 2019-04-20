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

Command* CommandFactory::getCommand(const TextList& gui, const SString& line) 
{
    switch (line.getData()[0])
    {
        case 'a': return new AppendCommand(); break;
        case 'p': return new PrintCommand(); break;
        case 'i': return new InsertCommand(); break;
        case 'd': return new DeleteCommand(); break;
        case 'x': return new ExtendCommand(); break;
        case 'l': return new LoadCommand(); break;
        case 's': return new SaveCommand(); break;
        case 'h': return new HelpCommand(); break;
        case 'q': return new QuitCommand(); break;
        default:
            return new HelpCommand();
            break;
    }
};
