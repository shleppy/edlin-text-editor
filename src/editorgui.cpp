/* author: Shelby Hendrickx */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "../include/editorgui.h"
#include "../include/sstring.h"
#include "../include/commands/commandfactory.h"
#include "../include/commands/command.h"

#include <iostream>
using namespace std;

EditorGUI::EditorGUI()
{
    text = new TextList();
}

EditorGUI::EditorGUI(const char* file)
{
    text = new TextList();

    std::ifstream fs(file);
    if (!fs.is_open()) return;
    std::string line;
    while (!fs.eof())
    {
        SString sline(line.c_str());
        std::getline(fs, line);
        text->appendLine(sline);
    }
    fs.close();
}

EditorGUI::~EditorGUI()
{
    delete text;
}

void EditorGUI::start()
{
    string line;
    bool running = true;
    while(running)
    {
        std::cout << "*";
        std::string line;
        std::getline(cin, line);

        SString *sline = new SString(line.c_str());

        Command *cmd = CommandFactory::getCommand(*text, sline->getData());

        int result = cmd->execute(*text, sline->getData());
        if (result == -1)
            std::cout << "Unhandled exception" << std::endl;

        delete cmd;
        delete sline;
    }
}
