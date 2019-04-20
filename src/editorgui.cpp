/* author: Shelby Hendrickx */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "../include/editorgui.h"
#include "../include/sstring.h"
#include "../include/commands/commandfactory.h"
#include "../include/commands/command.h"

EditorGUI::EditorGUI()
    :text{text}
{
    std::string fileName;
    std::cout << "Enter file name: ";
    std::getline(cin, fileName);
    file.open(fileName);
}

EditorGUI::EditorGUI(const char* file)
{
    std::ifstream fs(file);
    if (!fs.is_open()) return;
    std::string line;
    while (!fs.eof())
    {
        SString sline(line.c_str());
        std::getline(fs, line);
        text.appendLine(sline);
    }
}

EditorGUI::~EditorGUI()
{
    file.close();
}

void EditorGUI::start()
{
    bool running = true;
    while(running)
    {
        std::cout << "*";
        std::string line;
        std::getline(cin, line);

        SString *sline = new SString(line.c_str());

        Command *cmd = CommandFactory::getCommand(text, sline->getData());
        //currentCommand = cmd;

        int result = cmd->execute(text, *sline);
        if (result == -1)
            std::cout << "Unhandled exception" << std::endl;

        delete cmd;
        delete sline;
    }
}
