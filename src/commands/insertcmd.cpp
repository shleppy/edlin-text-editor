/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/insertcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
using namespace std;

InsertCommand::InsertCommand()
{}

int InsertCommand::execute(TextList& text, const SString& cmd)
{
    if (cmd.getLength() > 1)
    {
        // get number after first char (e.g.: with p352 we would need 352)
        size_t line = atol(cmd.getData() + 1); 
        text.printLine(line);
    }
    else
    {
        // print whole text file
        text.printAll();
    }
    return 0;
}

