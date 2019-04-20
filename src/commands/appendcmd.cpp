/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/appendcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
using namespace std;

AppendCommand::AppendCommand()
{}

int AppendCommand::execute(TextList& text, const SString& str)
{
    string line;
    bool isInvalid = true;
    while (isInvalid) 
    {
        cin >> line;
        if (line.length() <= 80) isInvalid = false;
    }

    SString ret(line.c_str());
    text.appendLine(ret);
    return 0;
}