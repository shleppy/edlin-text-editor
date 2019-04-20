/* author: Shelby Hendrickx */
#ifndef PRINT_COMMAND_H
#define PRINT_COMMAND_H
#include "command.h"

class PrintCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    PrintCommand();
};

#endif // PRINT_COMMAND_H