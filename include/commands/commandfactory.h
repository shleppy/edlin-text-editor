/* author: Shelby Hendrickx */
#pragma once
#include <iomanip>
#include "command.h"
#include "../sstring.h"
#include "../textlist.h"

class CommandFactory
{
    public:
        static void executeCommand(TextList* text, const SString& line);
};
