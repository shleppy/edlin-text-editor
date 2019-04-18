/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/command.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
using namespace std;

PrintCommand::PrintCommand(TextList const& text, SString const& cmd)
    :text{text}
{
    if (cmd.getLength > 1)
    {
        // get number after first char (e.g.: with p352 we would need 352)
    }
    else
    {
        // print whole text file
    }
}

