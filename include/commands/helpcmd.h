/* author: Shelby Hendrickx */
#ifndef HELP_COMMAND_H
#define HELP_COMMAND_H
#include "command.h"

class HelpCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    HelpCommand();
};

#endif // HELP_COMMAND_H