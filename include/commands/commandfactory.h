/* author: Shelby Hendrickx */
#pragma once
#include "command.h"
#include "../sstring.h"
#include "../textlist.h"

class CommandFactory
{
    public:
        static void executeCommand(TextList* gui, const SString& line);
};
