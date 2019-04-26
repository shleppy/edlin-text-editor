/* author: Shelby Hendrickx */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "../include/sstring.h"
#include "../include/editorgui.h"
#include "../include/commands/command.h"

#include <iostream>
using namespace std;

EditorGUI::EditorGUI()
    :text{new TextList()},
    manager{new CommandManager()}
{
}

EditorGUI::EditorGUI(const char* file)
    :text{new TextList()},
    manager{new CommandManager()}
{
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
    std::string line;
    bool running = true;
    while(running)
    {
        std::cout << endl << "*";
        std::string line;
        std::cin >> line;
        cin.ignore();

        SString sline(line.c_str());

        manager->executeCommand(text, sline);

    }
}
