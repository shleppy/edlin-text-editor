/* author: Shelby Hendrickx */
#ifndef EDITORGUI_H
#define EDITORGUI_C

#include <string>

enum class Commands {APPEND, PRINT, INSERT, DELETE, EXTEND, LOAD, SAVE, QUIT, HELP, INITIAL};

class EditorGUI 
{
    private:
        Commands currentCommand;

        Commands getCommand(string line);
    public:
        EditorGUI();
        void start();
};

#endif // EDITORGUI