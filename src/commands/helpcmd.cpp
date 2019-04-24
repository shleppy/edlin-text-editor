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
    std::cout << "  Text entry commands" << endl;
    std::cout << "    a        : append" << endl;
    std::cout << "    i [1..n] : insert at line" << endl << endl;
    std::cout << "  Text manipulation commands" << endl;
    std::cout << "    x [1..n] : extend text at line" << endl;
    std::cout << "    c [1..n] : replace given line completely" << endl;
    std::cout << "    m [1..n] : merge two consecutive lines" << endl;
    std::cout << "    t [1..n] : split a line starting at word" << endl << endl;
    std::cout << "  Text deletion commands" << endl;
    std::cout << "    q [1..n] : truncate line starting from character" << endl;
    std::cout << "    d [1..n] : delete text at line" << endl << endl;
    std::cout << "  Printing commands" << endl;
    std::cout << "    p [1..n] : print [at line]" << endl << endl; 
    std::cout << "  File manipulation commands" << endl;
    std::cout << "    l        : load file" << endl;
    std::cout << "    s        : save file" << endl << endl;
    std::cout << "  Exit commands" << endl;
    std::cout << "    h        : print this help text" << endl;
    std::cout << "    e        : exit application" << endl;
}
