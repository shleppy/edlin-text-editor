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

    cout << "got here" << endl;
    ifstream fs(file);
    if (!fs.is_open()) return;

    string line;
    while (!fs.eof()) 
    {
        getline(fs, line);
        SString *sline = new SString(line.c_str());
        text->appendLine(*sline);
        delete sline;
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
        cout << "*";
        string line;
        getline(cin, line);

        SString *sline = new SString(line.c_str());
        
        Command *cmd = CommandFactory::getCommand(*text, sline->getData());
        //currentCommand = cmd;

        int result = cmd->execute(*text, sline->getData());
        if (result == -1)
            cout << "Unhandled exception" << endl;
        
        delete cmd;
        delete sline;
    }
}

 
