/* author: Shelby Hendrickx */
#include <iostream>
#include "../../include/commands/commandmanager.h"
#include "../../include/commands/command.h"
#include "../../include/commands/undoable.h"
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
#include "../../include/commands/truncatecmd.h"
#include "../../include/commands/mergecmd.h"
#include "../../include/commands/splitcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

CommandManager::CommandManager()
    :undoStack{}, redoStack{}
{ }

CommandManager::~CommandManager()
{
    while(!undoStack.empty())
    {
        Undoable *tmp = undoStack.top();
        undoStack.pop();
        delete tmp;
    }
    while(!redoStack.empty())
    {
        Undoable *tmp = redoStack.top();
        redoStack.pop();
        delete tmp;
    }
}

void CommandManager::executeCommand(TextList *text, const SString& line) 
{
    // TODO fix mem management, use references over pointers
    switch (line.getData()[0])
    {

        case 'a':
        {
            Undoable *cmd = new AppendCommand();
            std::cout << "back here again" << std::endl;
            cmd->execute(*text, line);
            undoStack.push(cmd);
            break;
        }
        case 'i': 
        {
            Undoable *cmd = new InsertCommand();
            cmd->execute(*text, line);
            undoStack.push(cmd);
            break;
        }

        case 'x': 
        {
            Undoable *cmd = new ExtendCommand();
            cmd->execute(*text, line);
            undoStack.push(cmd);
            break;
        }
        case 'c':
        {
            Undoable *cmd = new ReplaceCommand();
            cmd->execute(*text, line);
            undoStack.push(cmd);
            break;
        }
        case 'm': 
        {
            Undoable *cmd = new MergeCommand();
            cmd->execute(*text, line);
            undoStack.push(cmd);
            break;
        }

        case 'q':
        {
            Undoable *cmd = new TruncateCommand();
            cmd->execute(*text, line);
            undoStack.push(cmd);
            break;
        }
        case 'd':
        {
            Undoable *cmd = new DeleteCommand();
            cmd->execute(*text, line);
            undoStack.push(cmd);
            break;
        }
        case 't':
        {
            Undoable *cmd = new SplitCommand();
            cmd->execute(*text, line);
            undoStack.push(cmd);
            break;
        }

        case 'p':
        {
            Command *cmd = new PrintCommand();
            cmd->execute(*text, line);
            break;
        }
        
        case 'l':
        { 
            Command *cmd = new LoadCommand();
            cmd->execute(*text, line);
            break;
        }
        case 's': 
        {
            Command *cmd = new SaveCommand();
            cmd->execute(*text, line);
            break;
        }

        case 'u':
        {
            Undoable *undo = undoStack.top();
            redoStack.push(undo);
            undoStack.pop();
            undo->undo(*text);
            break;
        }
        case 'r':
        {
            Undoable *redo = redoStack.top();
            undoStack.push(redo);
            redoStack.pop();
            redo->redo(*text);
            break;
        }
        case 'h':
        {
            Command *cmd = new HelpCommand();
            cmd->execute(*text, line);
            break;
        }
        case 'e':
        {
            Command *cmd = new QuitCommand();
            cmd->execute(*text, line);
            break;
        }
        default: 
        {
            Command *cmd = new HelpCommand(); 
            cmd->execute(*text, line);
            break;
        }
    }
};
