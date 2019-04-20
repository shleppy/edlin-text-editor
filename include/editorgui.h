/* author: Shelby Hendrickx */
#ifndef EDITORGUI_H
#define EDITORGUI_C

#include "commands/command.h"
#include "textlist.h"

class EditorGUI 
{
    private:
        /// Current state
        Command *currentCommand;
        TextList text;
    public:
        EditorGUI();
        EditorGUI(const char* file);
        void start();
};

#endif // EDITORGUI