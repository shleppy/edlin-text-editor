/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include <string>
#include "../../include/commands/appendcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
#include "../../include/textutils.h"
using namespace std;

AppendCommand::AppendCommand()
{}

int AppendCommand::execute(TextList& text, const SString& str)
{
    SString insText = TextUtils::getLineFromCin();
    text.appendLine(insText);

    return 0;
}
