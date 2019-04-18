/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/command.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
using namespace std;

AppendCommand::AppendCommand(TextList const& text)
    :text{text}
{}

int AppendCommand::execute()
{
    string line;
    bool isInvalid = true;
    while (isInvalid) 
    {
        cout << "*";
        cin >> line;
        if (line.length <= 80) isInvalid = false;
    }

    SString str(line.c_str);
    text.appendLine(str);
    return 0;
}