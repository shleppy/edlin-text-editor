/* author: Shelby Hendrickx */
#include <iomanip>
#include <iostream>
#include "../../include/textutils.h"
#include "../../include/commands/commandfactory.h"
#include "../../include/commands/truncatecmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
using namespace std;

TruncateCommand::TruncateCommand()
{}

int TruncateCommand::execute(TextList& text, const SString& cmd)
{
    size_t line = TextUtils::getLineNumberFromCommand(text, cmd);
    if (line == -1) return - 1;

    std::cout << "position: ";
    size_t position;
    std::cin >> position;

    text.truncateLine(line, position);
    return 0;
}
