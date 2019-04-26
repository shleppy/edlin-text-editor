/* author: Shelby Hendrickx */
#pragma once

#include "commands/commandmanager.h"
#include "textlist.h"

class EditorGUI
{
    private:
        //Command *currentCommand = nullptr;
        TextList *text;
        CommandManager *manager;
    public:
        EditorGUI();
        EditorGUI(const char* file);
        virtual ~EditorGUI();
        void start();
};
