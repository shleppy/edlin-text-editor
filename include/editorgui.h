/* author: Shelby Hendrickx */
#pragma once

#include <fstream>

#include "commands/command.h"
#include "textlist.h"

using namespace std;

class EditorGUI
{
    private:

        //Command *currentCommand = nullptr;
        TextList text;
        ofstream file;
    public:
        EditorGUI();
        EditorGUI(const char* file);
        virtual ~EditorGUI();
        void start();
};
