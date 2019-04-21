/* author: Shelby Hendrickx */
#include <iomanip>
#include "../../include/commands/deletecmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

#include <iostream>
using namespace std;

DeleteCommand::DeleteCommand()
{}

int DeleteCommand::execute(TextList& text, const SString& cmd)
{
    cout << "NOT IMPLEMENTED" << endl;
    return 0;
}
