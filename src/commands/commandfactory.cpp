/* author: Shelby Hendrickx */
#include <iostream>
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
#include "../../include/commands/replacecmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

void CommandFactory::executeCommand(TextList *text, const SString& line) 
{
    Command* cmd;
    switch (line.getData()[0])
    {
        case 'a': cmd = new AppendCommand(); break;
        case 'i': cmd = new InsertCommand(); break;
        
        case 'x': cmd = new ExtendCommand(); break;
        case 'c': cmd = new ReplaceCommand(); break;
        
        case 'd': cmd = new DeleteCommand(); break;
        
        case 'p': cmd = new PrintCommand(); break;
        
        case 'l': cmd = new LoadCommand(); break;
        case 's': cmd = new SaveCommand(); break;

        case 'h': cmd = new HelpCommand(); break;
        case 'e': cmd = new QuitCommand(); break;
        default: cmd = new HelpCommand(); break;
    }
    cmd->execute(*text, line);
};

size_t CommandFactory::getLineNumberFromCommand(TextList& text, const SString& line)
{
    size_t line_nr = atol(line.getData() + 1);
    if (line.getLength() <= 1 || line_nr > text.numberOfLines())
    {
        std::cout << "Invalid line" << std::endl;
        return -1;
    }
    return line_nr;
}