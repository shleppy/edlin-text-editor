/* author: Shelby Hendrickx */
#pragma once
#include "command.h"
#include "../sstring.h"
#include "../textlist.h"

class CommandFactory
{
    public:
        static Command* getCommand(const TextList& gui, const SString& line);
};
