/* author: Shelby Hendrickx */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "../include/editorgui.h"
#include "../include/sstring.h"
#include "../include/commands/commandfactory.h"
#include "../include/commands/command.h"

using namespace std;

EditorGUI::EditorGUI()
    :text{text}
{
    string fileName;
    cout << "Enter file name: ";
    getline(cin, fileName);
    file.open(fileName);
}

EditorGUI::EditorGUI(const char* file)
{
    ifstream fs(file);
    if (!fs.is_open()) return;
    string line;
    while (!fs.eof()) 
    {
        SString sline(line.c_str());
        getline(fs, line);
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
        cout << "*";
        string line;
        getline(cin, line);

        SString *sline = new SString(line.c_str());
        
        Command *cmd = CommandFactory::getCommand(text, sline->getData());
        //currentCommand = cmd;

        int result = cmd->execute(text, *sline);
        if (result == -1)
            cout << "Unhandled exception" << endl;
        
        delete cmd;
        delete sline;
    }
}

 
