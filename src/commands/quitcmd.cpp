/* author: Shelby Hendrickx */
#include <iostream>
#include "../../include/commands/quitcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

QuitCommand::QuitCommand()
{}

int QuitCommand::execute(TextList& text, const SString& cmd)
{
    cout << "NOT IMPLEMENTED" << endl;
    return 0;
}
