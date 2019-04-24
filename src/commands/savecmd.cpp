/* author: Shelby Hendrickx */
#include <iostream>
#include <fstream>

#include "../../include/commands/savecmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

SaveCommand::SaveCommand()
{}

int SaveCommand::execute(TextList& text, const SString& cmd)
{
    std::cout << "\"Quit with saving\"" << std::endl;
    std::string file;
    std::cin >> file;
    text.printAll(file);
    exit(0);
    return 0;
}
