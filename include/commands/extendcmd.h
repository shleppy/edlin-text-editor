/* author: Shelby Hendrickx */
#ifndef EXTEND_COMMAND_H
#define EXTEND_COMMANDH
#include "command.h"

class ExtendCommand : public Command
{
public:
    int execute(TextList& text, const SString& str) override;
    ExtendCommand();
};

#endif // EXTEND_COMMAND_H
