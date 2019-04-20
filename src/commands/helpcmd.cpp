/* author: Shelby Hendrickx */
#include <iostream>
#include "../../include/commands/helpcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"
using namespace std;

HelpCommand::HelpCommand()
{}

int HelpCommand::execute(TextList& text, const SString& cmd)
{
    printMenu();
    return 0;
}

void printMenu()
{
    cout << "NOT IMPLEMENTED" << endl;
}