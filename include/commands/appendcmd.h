/* author: Shelby Hendrickx */
#ifndef APPEND_COMMAND_H
#define APPEND_COMMAND_H
#include "command.h"

class AppendCommand : public Command 
{
public:
    int execute(TextList& text, const SString& str) override;
    AppendCommand();
};

#endif // APPEND_COMMAND_H