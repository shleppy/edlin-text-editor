/* author: Shelby Hendrickx */
#include <iostream>
#include <fstream>

#include "../../include/commands/loadcmd.h"
#include "../../include/sstring.h"
#include "../../include/textlist.h"

LoadCommand::LoadCommand()
{}

int LoadCommand::execute(TextList& text, const SString& cmd)
{
    // TODO  beautify
    if (text.isEmpty())
    {
        
        std::string file;
        std::cin >> file;

        std::ifstream fs(file);
        if (!fs.is_open())
        {
            std::cerr << "Can't open file!" << std::endl;
            return -1;
        }

        std::string line;
        while (!fs.eof())
        {
            SString sline(line.c_str());
            fs >> line;
            text.appendLine(sline);
        }
        fs.close();
        return 0;
    }
    else 
    {
        std::cout << "There is still text in the buffer" << std::endl;
        return 0;
    }
}

