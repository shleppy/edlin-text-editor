/* author: Shelby Hendrickx */
#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H
#include "command.h"
#include "../textlist.h"

class CommandFactory 
{
    public:
        static Command* getCommand(const TextList& gui, const SString& line);
};

#endif // COMMAND_FACTORY_H