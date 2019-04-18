/* author: Shelby Hendrickx */
#include "../../include/commands/commandfactory.h"
#include "../../include/commands/command.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

Command* CommandFactory::getCommand(TextList const& text, char* line) {
    const SString scmd(line);
    Command *cmd;
    switch (line[0]) 
    {
        case 'a': cmd = new AppendCommand(text);
        case 'p': cmd = new PrintCommand(text, scmd);
        case 'i': cmd = new InsertCommand(text, scmd);
        case 'd': cmd = new DeleteCommand(text, scmd);
        case 'x': cmd = new ExtendCommand(text, scmd);
        case 'l': cmd = new LoadCommand(text);
        case 's': cmd = new SaveCommand(text);
        case 'h': cmd = new HelpCommand(text);
        default: return nullptr;
    }
    return cmd;
}


