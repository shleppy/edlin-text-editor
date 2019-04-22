/* author: Shelby Hendrickx */
#include <iostream>
#include "../../include/commands/helpcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

using namespace std;

void printMenu();

HelpCommand::HelpCommand()
{}

int HelpCommand::execute(TextList& text, const SString& cmd)
{
    printMenu();
    return 0;
}

void printMenu()
{
    std::cout << "Commands:" << endl;
    std::cout << "  [a]       : append" << endl;
    std::cout << "  [i{1..n}] : insert at line" << endl;
    std::cout << "  [p{1..n}] : print {at line}" << endl;
    std::cout << "  [x{1..n}] : extend text at line" << endl;
    std::cout << "  [d{1..n}] : delete text at line" << endl;
    std::cout << "  [l]       : load file into text" << endl;
    std::cout << "  [s]       : save file" << endl;
    std::cout << "  [h]       : print this help text" << endl;
    std::cout << "  [q]       : quit application" << endl;
}
