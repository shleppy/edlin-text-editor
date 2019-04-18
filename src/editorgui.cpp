/* author: Shelby Hendrickx */
#include <iostream>
#include <string>
#include "../include/editorgui.h"

using namespace std;

EditorGUI::EditorGUI()
{
    currentCommand = Commands::INITIAL;
}

void EditorGUI::start()
{
    while(currentCommand != Commands::QUIT)
    {
        string line;
        cout << "*";
        try {
            getline(cin, line);
            getCommand(line);
        } catch (invalid_argument &e) {
            cerr << "Command not found: " << e.what() << endl;
        }
    }
}

Commands getCommand(string line)
{
    switch (line[0]) 
    {
        case 'a': return Commands::APPEND;
        case 'p': return Commands::PRINT;
        case 'i': return Commands::INSERT;
        case 'd': return Commands::DELETE;
        case 'x': return Commands::EXTEND;
        case 'l': return Commands::LOAD;
        case 's': return Commands::SAVE;
        case 'h': return Commands::HELP;
        default: throw new invalid_argument("Command not found");
    }
} 

 
